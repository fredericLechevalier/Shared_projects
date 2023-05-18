/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

static int event_team_created(connect_t *con)
{
    if (con->status != EVENT_TEAM_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_event_team_created(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

static int event_channel_created(connect_t *con)
{
    if (con->status != EVENT_CHANNEL_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *name = cjson_get_by_key(con->res, "name");
    char *description = cjson_get_by_key(con->res, "description");
    client_event_channel_created(uuid, name, description);
    free(uuid);
    free(name);
    free(description);
    return 1;
}

static int event_thread_created(connect_t *con)
{
    if (con->status != EVENT_THREAD_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *title = cjson_get_by_key(con->res, "title");
    char *body = cjson_get_by_key(con->res, "body");
    char *timestamp = cjson_get_by_key(con->res, "timestamp");
    char *user_uuid = cjson_get_by_key(con->res, "user_uuid");
    client_event_thread_created(uuid, user_uuid, atoi(timestamp), title, body);
    free(uuid);
    free(title);
    free(body);
    free(timestamp);
    free(user_uuid);
    return 1;
}

static int event_reply_created(connect_t *con)
{
    if (con->status != EVENT_REPLY_CREATED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *body = cjson_get_by_key(con->res, "body");
    char *user_uuid = cjson_get_by_key(con->res, "user_uuid");
    char *team_uuid = cjson_get_by_key(con->res, "team_uuid");
    client_event_thread_reply_received(team_uuid, uuid, user_uuid, body);
    free(uuid);
    free(body);
    free(user_uuid);
    free(team_uuid);
    return 1;
}

int event_create(connect_t *con)
{
    int tot = 0;
    tot += event_team_created(con);
    tot += event_channel_created(con);
    tot += event_thread_created(con);
    tot += event_reply_created(con);
    return tot;
}
