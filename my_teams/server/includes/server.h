/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define BUFFER_SIZE 4096

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
    #include <uuid/uuid.h>
    #include <signal.h>

    #include "../../libs/MyLib/includes/mylib.h"
    #include "../../libs/myteams/logging_server.h"
    #include "struct.h"
    #include "uuid.h"
    #include "codes.h"
    #include "utils.h"

void get_args(int ac, char **av, int *port);
connect_t *init_con(int port, int nb);
int accept_new_client(connect_t *con);
int handle_client(connect_t *con);
void handle_commands(client_t *client, connect_t *con);
void disconnect(connect_t *con);

void create_the_reply(char **args, client_t *client, connect_t *con);
bool check_users(char *user_uuid, char *team_uuid);
void invalid_command(client_t *client);
bool check_auth(client_t *client);
void list_subscirbed(client_t *client);



int login(client_t *client, connect_t *con, char *command);
int logout(client_t *client, connect_t *con, char *command);
int help(client_t *client, char *command);
int users(client_t *client, connect_t *con, char *command);
int user(client_t *client, connect_t *con, char *command);

bool update_messages(char *my_uuid, char *uuid, char *message);
int sendd(client_t *client, connect_t *con, char *command);
int messages(client_t *client, char *command);
int use(client_t *client, char *command);
int create(client_t *client, connect_t *con, char *command);
int list(client_t *client, char *command);
int subscribe(client_t *client, char *command);
int unsubscribe(client_t *client, char *command);
int subscribed(client_t *client, connect_t *con, char *command);
int info(client_t *client, char *command);

#endif // !SERVER_H_
