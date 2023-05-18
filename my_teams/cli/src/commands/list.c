/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

static int list_teams(connect_t *con)
{
    if (con->status != LIST_TEAM)
        return 0;
    char *teams_str = cjson_get_by_key(con->res, "data");
    char **teams = cjson_parse_array(teams_str);
    free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *decoded = decode_str(teams[i]);
        cjson *team_obj = cjson_parse_obj_str(decoded);
        free(decoded);
        char *name = cjson_get_by_key(team_obj, "name");
        char *description = cjson_get_by_key(team_obj, "description");
        char *uuid = cjson_get_by_key(team_obj, "uuid");
        client_print_teams(uuid, name, description);
        free(name);
        free(description);
        free(uuid);
        cjson_free(team_obj);
    }
    cjson_free_array(teams);
    return 1;
}

static int list_channels(connect_t *con)
{
    if (con->status != LIST_CHANNEL)
        return 0;
    char *channels_str = cjson_get_by_key(con->res, "data");
    char **channels = cjson_parse_array(channels_str);
    free(channels_str);
    for (int i = 0; channels[i]; ++i) {
        char *decoded = decode_str(channels[i]);
        cjson *channel_obj = cjson_parse_obj_str(decoded);
        free(decoded);
        char *name = cjson_get_by_key(channel_obj, "name");
        char *description = cjson_get_by_key(channel_obj, "description");
        char *uuid = cjson_get_by_key(channel_obj, "uuid");
        client_team_print_channels(uuid, name, description);
        free(name);
        free(description);
        free(uuid);
        cjson_free(channel_obj);
    }
    cjson_free_array(channels);
    return 1;
}

static int list_threads(connect_t *con)
{
    if (con->status != LIST_THREAD)
        return 0;
    char *threads_str = cjson_get_by_key(con->res, "data");
    char **threads = cjson_parse_array(threads_str);
    free(threads_str);
    for (int i = 0; threads[i]; ++i) {
        char *decoded = decode_str(threads[i]);
        cjson *thread_obj = cjson_parse_obj_str(decoded);
        free(decoded);
        char *title = cjson_get_by_key(thread_obj, "title");
        char *body = cjson_get_by_key(thread_obj, "body");
        char *uuid = cjson_get_by_key(thread_obj, "uuid");
        char *timestamp = cjson_get_by_key(thread_obj, "timestamp");
        client_channel_print_threads(uuid, con->uuid, atoi(timestamp), title,
        body);
        free(title);free(body);free(timestamp);free(uuid);
        cjson_free(thread_obj);
    }
    cjson_free_array(threads);
    return 1;
}

static int list_replies(connect_t *con)
{
    if (con->status != LIST_REPLY)
        return 0;
    char *replies_str = cjson_get_by_key(con->res, "data");
    char **replies = cjson_parse_array(replies_str);
    free(replies_str);
    for (int i = 0; replies[i]; ++i) {
        char *decoded = decode_str(replies[i]);
        cjson *reply_obj = cjson_parse_obj_str(decoded);
        free(decoded);
        char *body = cjson_get_by_key(reply_obj, "body");
        char *user_uuid = cjson_get_by_key(reply_obj, "user_uuid");
        char *timestamp = cjson_get_by_key(reply_obj, "timestamp");
        char *thread_uuid = cjson_get_by_key(reply_obj, "thread_uuid");
        client_thread_print_replies(thread_uuid, user_uuid, atoi(timestamp),
        body);
        free(body);free(timestamp);
        free(user_uuid);free(thread_uuid);
        cjson_free(reply_obj);
    }
    cjson_free_array(replies);return 1;
}

int list(connect_t *con)
{
    int tot = 0;
    tot += list_teams(con);
    tot += list_channels(con);
    tot += list_threads(con);
    tot += list_replies(con);
    return tot;
}
