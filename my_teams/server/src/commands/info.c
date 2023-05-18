/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static void info_thred(client_t *client)
{
    cjson *thread = get_thread(client->teams_context, client->channel_context,
    client->thread_context);
    char *uuid = cjson_get_by_key(thread, "uuid");
    char *user_uuid = cjson_get_by_key(thread, "user_uuid");
    char *timestamp = cjson_get_by_key(thread, "timestamp");
    char *title = cjson_get_by_key(thread, "title");
    char *body = cjson_get_by_key(thread, "body");
    client->res = cjson_push(NULL, 6, "status", STR_THREAD_INFO, "uuid",uuid,
    "title", title, "body", body, "timestamp", timestamp, "user_uuid",
    user_uuid);
    free(uuid);free(title);free(body);free(timestamp);free(user_uuid);
    cjson_free(thread);
}

static void info_channel(client_t *client)
{
    cjson *channel = get_channel(client->teams_context,
    client->channel_context);
    char *uuid = cjson_get_by_key(channel, "uuid");
    char *name = cjson_get_by_key(channel, "name");
    char *description = cjson_get_by_key(channel, "description");
    client->res = cjson_push(NULL, 4, "status", STR_CHANNEL_INFO, "uuid",
    uuid, "name", name, "description", description);
    free(uuid);
    free(name);
    free(description);
    cjson_free(channel);
}

static void info_team(client_t *client)
{
    cjson *team = get_team(client->teams_context);
    char *uuid = cjson_get_by_key(team, "uuid");
    char *name = cjson_get_by_key(team, "name");
    char *description = cjson_get_by_key(team, "description");
    client->res = cjson_push(NULL, 4, "status", STR_TEAM_INFO,
    "uuid",uuid, "name", name, "description", description);
    free(uuid);
    free(name);
    free(description);
    cjson_free(team);
}

static void info_users(client_t *client)
{
    client->res = cjson_push(NULL, 4,"status", STR_USER, "uuid", client->uuid,
    "username", client->user_name, "con", "1");
}

int info(client_t *client, char *command)
{
    if (!my_strcomp(command, "info"))
        return 0;
    if (!check_auth(client)) return 1;
    if (client->teams_context == NULL) {
        info_users(client);
        return 1;
    }
    if (client->channel_context == NULL) {
        info_team(client);
        return 1;
    }
    if (client->thread_context == NULL)
        info_channel(client);
    else
        info_thred(client);
    return 1;
}
