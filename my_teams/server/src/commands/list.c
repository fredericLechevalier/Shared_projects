/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static void list_replies(client_t *client)
{
    cjson *thread = get_thread(client->teams_context, client->channel_context,
client->thread_context);char **out = malloc(sizeof(char *) * 1);out[0] = NULL;
    char *replies_str = cjson_get_by_key(thread, "replies");cjson_free(thread);
    char **replies = cjson_parse_array(replies_str);free(replies_str);
    for (int i = 0; replies[i] != NULL; ++i) {
        char *reply = decode_str(replies[i]);
        cjson *reply_obj = cjson_parse_obj_str(reply);free(reply);
        char *body = cjson_get_by_key(reply_obj, "body");
        char *timestamp = cjson_get_by_key(reply_obj, "timestamp");
        char *user_uuid = cjson_get_by_key(reply_obj, "user_uuid");
        char *tmp = cjson_do_string(4, "body", body, "timestamp", timestamp,
        "user_uuid", user_uuid, "thread_uuid", client->thread_context);
        out = realloc(out, sizeof(char *) * (i + 2));
        out[i] = encode_str(tmp);free(tmp);out[i + 1] = NULL;
        free(body);free(timestamp);free(user_uuid);cjson_free(reply_obj);
    }
    cjson_free_array(replies);
    char *out_str = cjson_stringify_array(out);cjson_free_array(out);
    client->res = cjson_push(NULL, 2, "status", STR_LIST_REPLY, "data",
    out_str);free(out_str);
}

static void list_threads(client_t *client)
{
    cjson *channel = get_channel(client->teams_context,
    client->channel_context);char **out = malloc(sizeof(char *) * 1);out[0] =
NULL;char *threads_str = cjson_get_by_key(channel, "threads");cjson_free(
channel);char **threads = cjson_parse_array(threads_str);free(threads_str);
    for (int i = 0; threads[i] != NULL; ++i) {
        char *thread = decode_str(threads[i]);cjson *thread_obj =
cjson_parse_obj_str(thread);free(thread);char *title =
cjson_get_by_key(thread_obj, "title");char *body = cjson_get_by_key(
thread_obj, "body");char *timestamp = cjson_get_by_key(thread_obj, "timestamp"
);char *uuid = cjson_get_by_key(thread_obj, "uuid");char *tmp =
cjson_do_string(4, "title", title, "body",body, "uuid", uuid, "timestamp",
timestamp);out = realloc(out, sizeof(char *) * (i + 2));
        out[i] = encode_str(tmp);free(tmp);out[i + 1] = NULL;free(timestamp);
        free(title);free(body);free(uuid); cjson_free(thread_obj);
    }
    cjson_free_array(threads);
    char *out_str = cjson_stringify_array(out);cjson_free_array(out);
    client->res = cjson_push(NULL, 2, "status", STR_LIST_THREAD, "data",
    out_str);free(out_str);
}

static void list_channels(client_t *client)
{
    cjson *team = get_team(client->teams_context);
    char **out = malloc(sizeof(char *) * 1);out[0] = NULL;
    char *channels_str = cjson_get_by_key(team, "channels");cjson_free(team);
    char **channels = cjson_parse_array(channels_str);free(channels_str);
    for (int i = 0; channels[i] != NULL; ++i) {
        char *channel = decode_str(channels[i]);
        cjson *channel_obj = cjson_parse_obj_str(channel);free(channel);
        char *name = cjson_get_by_key(channel_obj, "name");
        char *description = cjson_get_by_key(channel_obj, "description");
        char *uuid = cjson_get_by_key(channel_obj, "uuid");
        char *tmp = cjson_do_string(3, "name", name, "description",
        description, "uuid", uuid);
        out = realloc(out, sizeof(char *) * (i + 2));
        out[i] = encode_str(tmp);free(tmp);out[i + 1] = NULL;
        free(name);free(description);free(uuid); cjson_free(channel_obj);
    }
    cjson_free_array(channels);
    char *out_str = cjson_stringify_array(out);cjson_free_array(out);
    client->res = cjson_push(NULL, 2, "status", STR_LIST_CHANNEL, "data",
    out_str);free(out_str);
}

static void list_teams(client_t *client)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char **out = malloc(sizeof(char *) * 1);out[0] = NULL;
    char *teams_str = cjson_get_by_key(file, "teams");cjson_free(file);
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    for (int i = 0; teams[i] != NULL; ++i) {
        char *team = decode_str(teams[i]);
        cjson *team_obj = cjson_parse_obj_str(team);free(team);
        char *name = cjson_get_by_key(team_obj, "name");
        char *description = cjson_get_by_key(team_obj, "description");
        char *uuid = cjson_get_by_key(team_obj, "uuid");
        char *tmp = cjson_do_string(3, "name", name, "description",
        description, "uuid", uuid);
        out = realloc(out, sizeof(char *) * (i + 2));
        out[i] = encode_str(tmp);free(tmp);out[i + 1] = NULL;
        free(name);free(description);free(uuid); cjson_free(team_obj);
    }
    cjson_free_array(teams);
    char *out_str = cjson_stringify_array(out);cjson_free_array(out);
    client->res = cjson_push(NULL, 2, "status", STR_LIST_TEAM, "data",
    out_str);free(out_str);
}

int list(client_t *client, char *command)
{
    if (!my_strcomp(command, "list"))
        return 0;
    if (!check_auth(client)) return 1;
    if (client->teams_context == NULL) {
        list_teams(client);
        return 1;
    }
    if (client->channel_context == NULL) {
        list_channels(client);
        return 1;
    }
    if (client->thread_context == NULL)
        list_threads(client);
    else
        list_replies(client);
    return 1;
}
