/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

int help(client_t *client, char *command)
{
    if (!my_strcomp(command, "help"))
        return 0;
    if (!check_auth(client)) return 1;
    client->res = cjson_push(NULL, 1, "status", STR_HELP);
    return 1;
}
