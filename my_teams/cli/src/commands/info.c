/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

static int info_thread(connect_t *con)
{
    if (con->status != THREAD_INFO)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *title = cjson_get_by_key(con->res, "title");
    char *body = cjson_get_by_key(con->res, "body");
    char *timestamp = cjson_get_by_key(con->res, "timestamp");
    char *user_uuid = cjson_get_by_key(con->res, "user_uuid");
    client_print_thread(uuid, user_uuid, atoi(timestamp), title, body);
    free(uuid);
    free(title);
    free(body);
    free(timestamp);
    free(user_uuid);
    return 1;
}

static int info_channel(connect_t *con)
{
    if (con->status != CHANNEL_INFO)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_print_channel(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

static int info_team(connect_t *con)
{
    if (con->status != TEAM_INFO)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_print_team(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

int info(connect_t *con)
{
    int tot = 0;
    tot += info_team(con);
    tot += info_channel(con);
    tot += info_thread(con);
    return tot;
}
