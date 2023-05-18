/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/client.h"

void get_args(int ac, char **av, int *ip, int *port)
{
    if (ac != 3)
        exit(84);
    if (my_strcomp(av[1], "-help")) {
        printf("USAGE: ./myteams_cli ip port\n\
\tip is the server ip address on which the server socket listens\n\
\tport is the port number on which the server socket listens\n");
        exit(0);
    }
    for (int i = 0; av[1][i]; ++i) {
        if (av[1][i] == '.' || i == 0) {
            (i != 0) ? (++i) : (0);
            (*ip) <<= 8;
            (*ip) += atoi(av[1] + i) % 256;
        }
    }
    *port = atoi(av[2]);
    if (*port <= 0 || *port > 65535)
        exit(84);
}
