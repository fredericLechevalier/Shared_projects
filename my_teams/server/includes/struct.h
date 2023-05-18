/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "server.h"

typedef struct {
    int sock;
    struct sockaddr_in data_addr;
    char *uuid;
    char *user_name;
    cjson *req;
    cjson *res;
    char *teams_context;
    char *channel_context;
    char *thread_context;
}client_t;

typedef struct {
    client_t *clients;
    int main_socket;
    int max_client;
    struct sockaddr_in addr;
    int addrlen;
    fd_set readfds;
    fd_set writefds;
} connect_t;

typedef bool magic_bool;

#endif // !STRUCT_H
