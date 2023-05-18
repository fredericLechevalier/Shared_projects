/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static char *get_status(connect_t *con, char *uuid)
{
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].sock != 0 && con->clients[i].uuid != NULL &&
        my_strcomp(con->clients[i].uuid, uuid))
            return "1";
    }
    return "0";
}

static void add_in_array(int size, char ***array, cjson *obj, connect_t *con)
{
    (*array) = realloc((*array), sizeof(char *) * (size + 2));
    char *uuid = cjson_get_by_key(obj, "uuid");
    char *username = cjson_get_by_key(obj, "username");
    char *status = get_status(con, uuid);
    char *str_obj = cjson_do_string(3, "uuid", uuid, "username",
    username, "status", status);
    (*array)[size] = encode_str(str_obj);
    free(str_obj);
    free(uuid);
    free(username);
}

static bool get_users(char ***array, connect_t *con, char *team_uuid)
{
    cjson *team = get_team(team_uuid);
    if (team == NULL)
        return false;
    char *users_str = cjson_get_by_key(team, "users");
    cjson_free(team);
    char **users = cjson_parse_array(users_str);
    free(users_str);
    char *tmp_user; cjson *tmp_user_obj;
    int i = 0;
    for (; users[i] != NULL; ++i) {
        tmp_user = decode_str(users[i]);
        tmp_user_obj = cjson_parse_obj_str(tmp_user);
        free(tmp_user);
        add_in_array(i, array, tmp_user_obj, con);
        cjson_free(tmp_user_obj);
    }
    (*array)[i] = NULL;
    cjson_free_array(users);
    return true;
}

static char *get_uuid(client_t *client)
{
    char *args_str = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(args_str); free(args_str);
    if (args[0] == NULL) {
        cjson_free_array(args);
        return NULL;
    }
    char *uuid = decode_str(args[0]);
    cjson_free_array(args);
    return uuid;
}

int subscribed(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "subscribed"))
        return 0;
    if (!check_auth(client)) return 1;
    char *team_uuid = get_uuid(client);
    if (team_uuid == NULL) {
        list_subscirbed(client);
        free(team_uuid);
    } else {
        char **array_out = NULL;
        if (get_users(&array_out, con, team_uuid)) {
            char *array_str = cjson_stringify_array(array_out);
            cjson_free_array(array_out);
            client->res = cjson_push(NULL, 2, "status", STR_USERS, "data",
            array_str);free(array_str);
        } else
            client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM,
            "uuid", team_uuid);free(team_uuid);
    }
    return 1;
}
