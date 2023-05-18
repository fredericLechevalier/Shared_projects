/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static char *do_sub(client_t *client, cjson *team)
{
    char *users_str = cjson_get_by_key(team, "users");
    char **users = cjson_parse_array(users_str);
    free(users_str);
    int len = 0;
    for (; users[len]; ++len);
    users = realloc(users, sizeof(char *) * (len + 2));
    char *tmp = cjson_do_string(2, "uuid", client->uuid, "username",
client->user_name);
    users[len] = encode_str(tmp);free(tmp);
    users[len + 1] = NULL;
    users_str = cjson_stringify_array(users);
    cjson_free_array(users);
    cjson_set_by_key(team, "users", users_str);free(users_str);
    char *team_str = cjson_get_obj_str(team, false);
    return team_str;
}

static void do_sub_get_team(client_t *client, char *uuid)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(uuid, tmp_uuid)) {
            char *new_users = do_sub(client, tmp_obj);
            free(teams[i]);free(tmp_uuid);
            teams[i] = encode_str(new_users);
            free(new_users);cjson_free(tmp_obj);break;
        }
        free(tmp_uuid);cjson_free(tmp_obj);
    }
    teams_str = cjson_stringify_array(teams);cjson_free_array(teams);
    cjson_set_by_key(file, "teams", teams_str);free(teams_str);
    cjson_write_file("server.cjson", O_CREAT | O_TRUNC, file);
    cjson_free(file);
}

static char *get_uuid(client_t *client)
{
    char *args_str = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(args_str); free(args_str);
    if (args == NULL || args[0] == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "Missing paramater");
        cjson_free_array(args);
        return NULL;
    }
    char *out = decode_str(args[0]);
    cjson_free_array(args);
    return out;
}

int subscribe(client_t *client, char *command)
{
    if (!my_strcomp(command, "subscribe"))
        return 0;
    if (!check_auth(client)) return 1;
    char *uuid = get_uuid(client);
    if (uuid == NULL)
        return 1;
    cjson *tmp = get_team(uuid);
    if (tmp == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM, "uuid",
        uuid);free(uuid);
        return 1;
    }
    cjson_free(tmp);
    do_sub_get_team(client, uuid);
    client->res = cjson_push(NULL, 2, "status", STR_SUBSCRIBED, "uuid", uuid);
    free(uuid);
    return 1;
}
