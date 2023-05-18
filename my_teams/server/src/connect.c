/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../includes/server.h"

struct sockaddr_in init_addr(int port)
{
    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons((in_port_t)port);
    myaddr.sin_addr.s_addr = INADDR_ANY;
    return myaddr;
}

static void init_cli(connect_t *out)
{
    for (int i = 0; i < out->max_client; ++i) {
        out->clients[i].sock = 0;
        out->clients[i].user_name = NULL;
        out->clients[i].uuid = NULL;
        out->clients[i].req = NULL;
        out->clients[i].res = NULL;
        out->clients[i].teams_context = NULL;
        out->clients[i].channel_context = NULL;
        out->clients[i].thread_context = NULL;
    }
}

connect_t *init_con(int port, int nb)
{
    connect_t *out = malloc(sizeof(connect_t));
    out->max_client = nb;
    out->clients = malloc(sizeof(client_t) * out->max_client);
    out->addr = init_addr(port);
    out->addrlen = sizeof(out->addr);
    init_cli(out);
    if ((out->main_socket = socket(PF_INET, SOCK_STREAM, 0)) == 0)
        return NULL;
    int opt = 1;
    if (setsockopt(out->main_socket, SOL_SOCKET, SO_REUSEADDR, &opt,
sizeof(opt)) < 0)
        return NULL;
    if (bind(out->main_socket, (struct sockaddr *)&out->addr,
out->addrlen) == -1 || listen(out->main_socket, 3) < 0)
        return NULL;
    return out;
}

int accept_new_client(connect_t *con)
{
    int new;
    int i;
    if (FD_ISSET(con->main_socket, &con->readfds)) {
        if ((new = accept(con->main_socket, (struct sockaddr *)&con->addr,
(socklen_t *)&con->addrlen)) < 0)
            return 84;
        for (i = 0; i < con->max_client && con->clients[i].sock != 0;  ++i);
        con->clients[i].sock = new;
        con->clients[i].res = cjson_push(NULL, 1, "status", STR_CONNECTED);
    }
    return 0;
}
