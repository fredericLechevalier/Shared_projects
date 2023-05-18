/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int subscribe(connect_t *con)
{
    if (con->status != SUBSCRIBED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    client_print_subscribed(con->uuid, uuid);
    free(uuid);
    return 1;
}

int unsubscribe(connect_t *con)
{
    if (con->status != UNSUBSCRIBED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    client_print_unsubscribed(con->uuid, uuid);
    free(uuid);
    return 1;
}
