/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/
#include "../includes/client.h"

void free_con(connect_t *con)
{
    if (con == NULL)
        return;
    if (con->uuid)
        free(con->uuid);
    con->uuid = NULL;
    if (con->command)
        cjson_free(con->command);
    con->command = NULL;
    if (con->res)
        cjson_free(con->res);
    con->res = NULL;
    free(con);
}

connect_t *init_con(int ip, int port)
{
    ip = ip;
    connect_t *out = malloc(sizeof(connect_t));
    out->socket = socket(PF_INET, SOCK_STREAM, 0);
    if (out->socket == -1)
        exit(84);
    out->addr.sin_family = AF_INET;
    out->addr.sin_port = htons((in_port_t) port);
    out->addr.sin_addr.s_addr = INADDR_ANY;
    out->addrlen = sizeof(out->addr);
    out->res = NULL;
    out->uuid = NULL;
    out->command = NULL;
    out->wait_server = true;
    if (connect(out->socket, (struct sockaddr *)&out->addr, out->addrlen)
    == -1) {
        close(out->socket); free(out);
        exit(84);
    }
    return out;
}
