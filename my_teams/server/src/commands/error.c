/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

void invalid_command(client_t *client)
{
    client->res = cjson_push(NULL, 2, "status", STR_BAD_REQUEST, "message",
    "Unknow command");
}
