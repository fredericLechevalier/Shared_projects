/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int other_login(connect_t *con)
{
    if (con->status != OTHER_LOGED_IN)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *username = cjson_get_by_key(con->res, "username");
    client_event_logged_in(uuid, username);
    free(username);
    free(uuid);
    return 1;
}

int other_logout(connect_t *con)
{
    if (con->status != OTHER_LOGED_OUT)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *username = cjson_get_by_key(con->res, "username");
    client_event_logged_out(uuid, username);
    free(username);
    free(uuid);
    return 1;
}

int login(connect_t *con)
{
    if (con->status != LOGED_IN)
        return 0;
    con->uuid = cjson_get_by_key(con->res, "uuid");
    char *username = cjson_get_by_key(con->res, "username");
    client_event_logged_in(con->uuid, username);
    free(username);
    return 1;
}

int logout(connect_t *con)
{
    if (con->status != LOGED_OUT)
        return 0;
    char *username = cjson_get_by_key(con->res, "username");
    client_event_logged_out(con->uuid, username);
    free(username);
    free(con->uuid);
    con->uuid = NULL;
    return 1;
}

int connection(connect_t *con)
{
    if (con->status != CONNECTED)
        return 0;
    printf("connection established\n");
    return 1;
}
