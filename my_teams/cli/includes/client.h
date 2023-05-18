/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/time.h>
    #include <stdbool.h>
    #include <string.h>
    #include <time.h>
    #include <signal.h>

    #include "../../libs/MyLib/includes/mylib.h"
    #include "../../libs/myteams/logging_client.h"
    #include "struct.h"
    #include "codes.h"




void get_args(int ac, char **av, int *ip, int *port);
connect_t *init_con(int ip, int port);
void get_command(connect_t *con);
void handle_res(connect_t *con);
void communicate(connect_t *con);

void unknow_response(void);

void free_con(connect_t *con);

int login(connect_t *con);
int logout(connect_t *con);
int connection(connect_t *con);
int help(connect_t *con);
int error(connect_t *con);
int users(connect_t *con);
int user(connect_t *con);
int messages(connect_t *con);
int nothing(connect_t *con);
int list(connect_t *con);
int unsubscribe(connect_t *con);
int subscribe(connect_t *con);
int info(connect_t *con);
int create(connect_t *con);
int received(connect_t *con);
int other_logout(connect_t *con);
int other_login(connect_t *con);
int event_create(connect_t *con);

#endif // !CLIENT_H_
