/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static void write_user(bool new, cjson *user)
{
    char *uuid = cjson_get_by_key(user, "uuid");
    char *username = cjson_get_by_key(user, "username");
    if (new)
        server_event_user_created(uuid, username);
    else
        server_event_user_logged_in(uuid);
    free(uuid);
    free(username);
}

static cjson *get_auth(client_t *client)
{
    char *args_str = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(args_str);
    free(args_str);
    if (args == NULL || args[0] == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "No username");
        cjson_free_array(args);
        return NULL;
    }
    char *decoded_username = decode_str(args[0]);
    cjson *user = get_user_by_username(decoded_username);
    if (user == NULL) {
        user = create_user(decoded_username);
        write_user(true, user);
    }
    write_user(false, user);
    free(decoded_username);
    cjson_free_array(args);
    return user;
}

int login(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "login"))
        return 0;
    if (client->user_name != NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_ALREADY_AUTH,
        "message", "Already connected");return 1;
    }
    cjson *user = get_auth(client);
    if (user == NULL) return 1;
    client->uuid = cjson_get_by_key(user, "uuid");
    client->user_name = cjson_get_by_key(user, "username");
    client->res = cjson_push(NULL, 3, "status", STR_LOGED_IN, "uuid",
    client->uuid, "username", client->user_name);
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].uuid != NULL && my_strcomp(con->clients[i].uuid,
        client->uuid) == false)
            con->clients[i].res = cjson_push(NULL, 3, "status",
STR_OTHER_LOGED_IN, "uuid", client->uuid, "username", client->user_name);
    }
    cjson_free(user);return 1;
}
