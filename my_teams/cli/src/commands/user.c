/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int user(connect_t *con)
{
    if (con->status != USER)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *username = cjson_get_by_key(con->res, "username");
    char *status = cjson_get_by_key(con->res, "con");
    client_print_user(uuid, username, atoi(status));
    free(status);
    free(username);
    free(uuid);
    return 1;
}
