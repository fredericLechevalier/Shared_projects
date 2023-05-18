/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/server.h"

void get_args(int ac, char **av, int *port)
{
    if (ac != 2)
        exit(84);
    if (my_strcomp(av[1], "-help")) {
        printf("USAGE: ./myteams_server port\n\
\tport is the port number on which the server socket listens.\n");
        exit(0);
    }
    *port = atoi(av[1]);
    if (*port <= 0 || *port > 65535)
        exit(84);
}
