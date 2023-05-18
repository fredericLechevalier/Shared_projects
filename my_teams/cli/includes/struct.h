/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "client.h"

typedef struct {
    int socket;
    struct sockaddr_in addr;
    int addrlen;
    char *uuid;
    fd_set readfd;
    fd_set writefd;
    cjson *command;
    cjson *res;
    int status;
    bool wait_server;
    fd_set user_input;
} connect_t;


#endif // !STRUCT_H
