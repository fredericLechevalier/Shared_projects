/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../includes/server.h"

magic_bool closing;

static int main_clock(connect_t *con)
{
    int highest;
    int tmp;
    while (true) {
        highest = con->main_socket;
        FD_ZERO(&con->readfds);FD_ZERO(&con->writefds);
        FD_SET(con->main_socket, &con->readfds);
        FD_SET(con->main_socket, &con->writefds);
        for (int i = 0; i < con->max_client; ++i) {
            tmp = con->clients[i].sock;
            (tmp > highest) ? (highest = tmp) : 0;
            (tmp > 0) ? (FD_SET( tmp , &con->readfds)) : 0;
            (tmp > 0) ? (FD_SET( tmp , &con->writefds)) : 0;
        }
        if (select(highest + 1, &con->readfds, &con->writefds,
        NULL, NULL) == -1) return 0;
        if (closing) return 0;
        if (accept_new_client(con) == 84) return 84;
        if (handle_client(con) == 84) return 84;
    }
    return 0;
}

void catch_sig(int sig)
{
    sig = sig;
    printf("\nclosing server\n");
    closing = true;
}

int main(int ac, char **av)
{
    closing = false;
    signal(SIGINT, catch_sig);
    srand(time(NULL));
    int port;
    get_args(ac, av, &port);
    connect_t *con = init_con(port, 30);
    if (!con)
        return 84;
    if (main_clock(con) == 84)
        return 84;
    disconnect(con);
    return 0;
}
