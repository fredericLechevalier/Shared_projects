/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

bool check_auth(client_t *client)
{
    if (client->uuid == NULL || client->user_name == NULL) {
        client->res = cjson_push(NULL, 1, "status", STR_UNAUTHORIZED);
        return false;
    }
    return true;
}
