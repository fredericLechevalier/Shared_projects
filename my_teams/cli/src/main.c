/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/client.h"


connect_t *con;

static void do_select(connect_t *con)
{
    FD_ZERO(&con->readfd);
    FD_ZERO(&con->writefd);
    FD_ZERO(&con->user_input);
    FD_SET(0, &con->user_input);
    FD_SET(con->socket, &con->readfd);
    FD_SET(con->socket, &con->writefd);
    if (select(con->socket + 1, &con->readfd, &con->writefd, NULL,
    &((struct timeval) {0, 100})) == -1) {
        free_con(con);
        exit(0);
    }
    if (select(1, &con->user_input, NULL, NULL,
    &((struct timeval) {0, 100})) == -1) {
        free_con(con);
        exit(0);
    }
}

static void main_clock(connect_t *con)
{
    while (true) {
        do_select(con);
        get_command(con);
        handle_res(con);
        communicate(con);
    }
}

void catch_sig(int sig)
{
    sig = sig;
    printf("\nclosing client\n");
    free_con(con);
    exit(0);
}

int main(int ac, char **av)
{
    signal(SIGINT, catch_sig);
    int ip, port;
    get_args(ac, av, &ip, &port);
    con = init_con(ip, port);

    main_clock(con);
    close(con->socket);
    return 0;
}
