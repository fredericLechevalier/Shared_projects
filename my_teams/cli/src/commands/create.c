/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

static int thread_create(connect_t *con)
{
    if (con->status != THREAD_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *title = cjson_get_by_key(con->res, "title");
    char *body = cjson_get_by_key(con->res, "body");
    char *timestamp = cjson_get_by_key(con->res, "timestamp");
    char *user_uuid = cjson_get_by_key(con->res, "user_uuid");
    client_print_thread_created(uuid, user_uuid, atoi(timestamp), title, body);
    client_event_thread_created(uuid, user_uuid, atoi(timestamp), title, body);
    free(uuid);
    free(title);
    free(body);
    free(timestamp);
    free(user_uuid);
    return 1;
}

static int channel_create(connect_t *con)
{
    if (con->status != CHANNEL_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_print_channel_created(uuid, name, description);
    client_event_channel_created(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

static int team_create(connect_t *con)
{
    if (con->status != TEAM_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_print_team_created(uuid, name, description);
    client_event_team_created(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

static int reply_create(connect_t * con)
{
    if (con->status != REPLY_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *body = cjson_get_by_key(con->res, "body");
    char *timestamp = cjson_get_by_key(con->res, "timestamp");
    char *user_uuid = cjson_get_by_key(con->res, "user_uuid");
    char *team_uuid = cjson_get_by_key(con->res, "team_uuid");
    client_print_reply_created(uuid, user_uuid, atoi(timestamp), body);
    client_event_thread_reply_received(team_uuid, uuid, user_uuid, body);
    free(uuid);
    free(body);
    free(timestamp);
    free(user_uuid);
    free(team_uuid);
    return 1;
}

int create(connect_t *con)
{
    int tot = 0;
    tot += team_create(con);
    tot += channel_create(con);
    tot += thread_create(con);
    tot += reply_create(con);
    return tot;
}
