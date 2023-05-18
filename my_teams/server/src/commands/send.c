/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static char **parse_args(client_t *client)
{
    char *args_str = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(args_str); free(args_str);
    if (args == NULL || args[0] == NULL || args[1] == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "Missing paramaters");
        cjson_free_array(args);
        return NULL;
    }
    return args;
}

static void ping_dest(connect_t *con, char *dest_uuid, char *me_uuid,
char *message)
{
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].sock != 0 && con->clients[i].uuid != NULL &&
        my_strcomp(dest_uuid, con->clients[i].uuid))
            con->clients[i].res = cjson_push(NULL, 3, "status",
            STR_MESSAGE_RECEIVED, "uuid", me_uuid, "message", message);
    }
}

int sendd(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "send"))
        return 0;
    if (!check_auth(client)) return 1;
    char **args = parse_args(client);
    if (args == NULL)
        return 1;
    char *uuid = decode_str(args[0]);
    char *message = decode_str(args[1]);
    cjson_free_array(args);
    if (update_messages(client->uuid, uuid, message) == false)
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_USER, "uuid",
        uuid);
    else {
        server_event_private_message_sended(client->uuid, uuid, message);
        client->res = cjson_push(NULL, 1, "status", STR_DO_NOTHING);
        ping_dest(con, uuid, client->uuid, message);
    }
    free(uuid);
    free(message);
    return 1;
}
