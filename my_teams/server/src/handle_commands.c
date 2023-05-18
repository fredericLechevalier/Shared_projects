/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../includes/server.h"

void handle_commands(client_t *client, connect_t *con)
{
    char *command = cjson_get_by_key(client->req, "command");
    int tot = 0;
    tot += login(client, con, command);
    tot += logout(client, con, command);
    tot += help(client, command);
    tot += users(client, con, command);
    tot += user(client, con, command);
    tot += sendd(client, con, command);
    tot += messages(client, command);
    tot += use(client, command);
    tot += create(client, con, command);
    tot += list(client, command);
    tot += subscribe(client, command);
    tot += unsubscribe(client, command);
    tot += subscribed(client, con, command);
    tot += info(client, command);
    if (tot == 0)
        invalid_command(client);
    free(command);
}
