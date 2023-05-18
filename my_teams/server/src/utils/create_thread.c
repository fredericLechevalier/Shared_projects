/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"


static char *add_in_channel(cjson *channel, cjson *new_thread)
{
    char *thread_str = cjson_get_by_key(channel, "threads");
    char **threads = cjson_parse_array(thread_str);
    free(thread_str);
    int len = 0;
    for (; threads[len]; ++len);
    threads = realloc(threads, sizeof(char *) * (len + 2));
    char *new_thread_str = cjson_get_obj_str(new_thread, false);
    threads[len] = encode_str(new_thread_str);
    threads[len + 1] = NULL;
    free(new_thread_str);
    thread_str = cjson_stringify_array(threads);
    cjson_free_array(threads);
    cjson_set_by_key(channel, "threads", thread_str);
    free(thread_str);
    char *channel_str = cjson_get_obj_str(channel, false);
    char *encoded_channel = encode_str(channel_str);
    free(channel_str);
    return encoded_channel;
}

static char *add_in_team(cjson *team, char *channel_uuid, cjson *new_thread)
{
    char *channels_str = cjson_get_by_key(team, "channels");
    char **channels = cjson_parse_array(channels_str);free(channels_str);
    for (int i = 0; channels[i]; ++i) {
        char *tmp = decode_str(channels[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(tmp_uuid, channel_uuid)) {
            char *new_thread_str = add_in_channel(tmp_obj, new_thread);
            free(tmp_uuid);free(channels[i]);channels[i] = new_thread_str;
            cjson_free(tmp_obj);break;
        }
        cjson_free(tmp_obj);free(tmp_uuid);
    }
    channels_str = cjson_stringify_array(channels);cjson_free_array(channels);
    cjson_set_by_key(team, "channels", channels_str);free(channels_str);
    char *team_str = cjson_get_obj_str(team, false);
    char *encoded_team = encode_str(team_str);free(team_str);
    return encoded_team;
}

cjson *create_thread(char **uuids, char *name, char *description,
char *user_uuid)
{
    char *uuid = gen_uuid();char *timestamp = my_itoa((int)time(NULL));
    cjson *new_thread = cjson_push(NULL, 6, "uuid", uuid, "title", name,
"body", description, "replies", "[]", "timestamp", timestamp, "user_uuid",
user_uuid);free(timestamp);cjson *file = cjson_read_file("server.cjson",
BUFFER_SIZE);char *teams_str = cjson_get_by_key(file, "teams");
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]); cjson *tmp_obj =
cjson_parse_obj_str(tmp);free(tmp);char *tmp_uuid = cjson_get_by_key(tmp_obj,
"uuid"); if (my_strcomp(tmp_uuid, uuids[0])) {
            char *new_channel_str = add_in_team(tmp_obj, uuids[1], new_thread);
            free(tmp_uuid);free(teams[i]);teams[i] = new_channel_str;
            cjson_free(tmp_obj);break;
        } cjson_free(tmp_obj);free(tmp_uuid);
    } teams_str = cjson_stringify_array(teams);cjson_free_array(teams);
    cjson_set_by_key(file, "teams", teams_str);free(teams_str);
    cjson_write_file("server.cjson", O_CREAT | O_TRUNC, file);
    cjson_free(file);free(uuid);return new_thread;
}
