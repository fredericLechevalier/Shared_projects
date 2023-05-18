/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../includes/server.h"

void disconnect(connect_t *con)
{
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].uuid != NULL)
            free(con->clients[i].uuid);
        if (con->clients[i].user_name != NULL)
            free(con->clients[i].user_name);
        if (con->clients[i].req != NULL)
            cjson_free(con->clients[i].req);
        if (con->clients[i].res != NULL)
            cjson_free(con->clients[i].res);
        if (con->clients[i].thread_context != NULL)
            free(con->clients[i].thread_context);
        if (con->clients[i].channel_context != NULL)
            free(con->clients[i].channel_context);
        if (con->clients[i].teams_context != NULL)
            free(con->clients[i].teams_context);
        if (con->clients[i].sock != 0)
            close(con->clients[i].sock);
    }if (con->clients)free(con->clients);
    con->clients = NULL;close(con->main_socket);
    if (con)free(con);con = NULL;
}
