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

static char *get_arg(client_t *client)
{
    char *str_args = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(str_args);
    free(str_args);
    if (args == NULL || args[0] == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "No uuid");
        cjson_free_array(args);
        return NULL;
    }
    char *out = decode_str(args[0]);
    cjson_free_array(args);
    return out;
}

int user(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "user"))
        return 0;
    if (!check_auth(client)) return 1;
    char *uuid = get_arg(client);
    if (uuid == NULL)
        return 1;
    cjson *user = get_user_by_uuid(uuid);
    if (user == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_USER,
    "uuid", uuid);
        free(uuid);return 1;
    }
    free(uuid);
    char *uuid_out = cjson_get_by_key(user, "uuid");
    char *username_out = cjson_get_by_key(user, "username");
    char *status = get_status(con, uuid_out);
    client->res = cjson_push(NULL, 4,"status", STR_USER, "uuid", uuid_out,
    "username", username_out, "con", status);
    free(uuid_out);free(username_out);cjson_free(user);
    return 1;
}
