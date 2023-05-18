/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static char *add_in_thread(cjson *thread, cjson *new_reply)
{
    char *replies_str = cjson_get_by_key(thread, "replies");
    char **replies = cjson_parse_array(replies_str);
    free(replies_str);
    int len = 0;
    for (; replies[len]; ++len);
    replies = realloc(replies, sizeof(char *) * (len + 2));
    char *new_reply_str = cjson_get_obj_str(new_reply, false);
    replies[len] = encode_str(new_reply_str);
    replies[len + 1] = NULL;
    free(new_reply_str);
    replies_str = cjson_stringify_array(replies);
    cjson_free_array(replies);
    cjson_set_by_key(thread, "replies", replies_str);
    free(replies_str);
    char *thread_str = cjson_get_obj_str(thread, false);
    char *encoded_thread = encode_str(thread_str);
    free(thread_str);
    return encoded_thread;
}

static char *add_in_channel(cjson *channel, char *thread_uuid,
cjson *new_reply)
{
    char *threads_str = cjson_get_by_key(channel, "threads");
    char **threads = cjson_parse_array(threads_str);free(threads_str);
    for (int i = 0; threads[i]; ++i) {
        char *tmp = decode_str(threads[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(tmp_uuid, thread_uuid)) {
            char *new_reply_str = add_in_thread(tmp_obj, new_reply);
            free(threads[i]);threads[i] = new_reply_str;cjson_free(tmp_obj);
            free(tmp_uuid);break;
        }cjson_free(tmp_obj);free(tmp_uuid);
    }
    threads_str = cjson_stringify_array(threads);cjson_free_array(threads);
    cjson_set_by_key(channel, "threads", threads_str);free(threads_str);
    char *channel_str = cjson_get_obj_str(channel, false);
    char *encoded_channel = encode_str(channel_str);free(channel_str);
    return encoded_channel;
}

static char *add_in_team(cjson *team, char *channel_uuid, char *thread_uuid,
cjson *new_reply)
{
    char *channels_str = cjson_get_by_key(team, "channels");
    char **channels = cjson_parse_array(channels_str);free(channels_str);
    for (int i = 0; channels[i]; ++i) {
        char *tmp = decode_str(channels[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(tmp_uuid, channel_uuid)) {
            char *new_thread_str = add_in_channel(tmp_obj, thread_uuid,
            new_reply);free(tmp_uuid);free(channels[i]);
            channels[i] = new_thread_str;cjson_free(tmp_obj);break;
        }
        cjson_free(tmp_obj);free(tmp_uuid);
    }
    channels_str = cjson_stringify_array(channels);cjson_free_array(channels);
    cjson_set_by_key(team, "channels", channels_str);free(channels_str);
    char *team_str = cjson_get_obj_str(team, false);
    char *encoded_team = encode_str(team_str);free(team_str);
    return encoded_team;
}

cjson *create_reply(char **loc_uuids, char *content, char *user_uuid)
{
    char *uuid = gen_uuid();char *timestamp = my_itoa((int)time(NULL));
    cjson *new_reply = cjson_push(NULL, 4, "uuid", uuid, "body", content,
"user_uuid", user_uuid, "timestamp", timestamp);free(timestamp);
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(tmp_uuid, loc_uuids[0])) {
            char *new_channel_str = add_in_team(tmp_obj, loc_uuids[1],
            loc_uuids[2], new_reply);free(tmp_uuid);free(teams[i]);
            teams[i] = new_channel_str;cjson_free(tmp_obj);break;
        } cjson_free(tmp_obj);free(tmp_uuid);
    } teams_str = cjson_stringify_array(teams);
    cjson_free_array(teams);cjson_set_by_key(file, "teams", teams_str);
    free(teams_str);cjson_write_file("server.cjson", O_CREAT | O_TRUNC, file);
    cjson_free(file);free(uuid);return new_reply;
}
