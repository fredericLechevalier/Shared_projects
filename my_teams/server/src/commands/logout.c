/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

int logout(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "logout"))
        return 0;
    if (!check_auth(client)) return 1;
    if (client->user_name == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_NOT_AUTH,
        "message", "Not connected");
        return 1;
    }
    client->res = cjson_push(NULL, 3, "status", STR_LOGED_OUT, "uuid" ,
    client->uuid, "username", client->user_name);
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].uuid != NULL && my_strcomp(con->clients[i].uuid,
        client->uuid) == false)
            con->clients[i].res = cjson_push(NULL, 3, "status",
            STR_OTHER_LOGED_OUT, "uuid" ,
    client->uuid, "username", client->user_name);
    }
    server_event_user_logged_out(client->uuid);
    free(client->user_name);free(client->uuid);
    client->user_name = NULL;client->uuid = NULL;return 1;
}
