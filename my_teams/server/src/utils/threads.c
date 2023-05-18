/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

cjson *get_thread_by_title(char *team_uuid, char *channel_uuid, char *title)
{
    cjson *channel = get_channel(team_uuid, channel_uuid);
    char *threads_str = cjson_get_by_key(channel, "threads");
    cjson_free(channel);
    char **threads = cjson_parse_array(threads_str);
    free(threads_str);
    for (int i = 0; threads[i]; ++i) {
        char *tmp = decode_str(threads[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_title = cjson_get_by_key(tmp_obj, "title");
        if (my_strcomp(title, tmp_title)) {
            free(tmp_title);
            cjson_free_array(threads);
            return tmp_obj;
        }
        free(tmp_title);
        cjson_free(tmp_obj);
    }
    cjson_free_array(threads);
    return NULL;
}

cjson *get_thread(char *team_uuid, char *channel_uuid, char *uuid)
{
    cjson *channel = get_channel(team_uuid, channel_uuid);
    char *threads_str = cjson_get_by_key(channel, "threads");
    cjson_free(channel);
    char **threads = cjson_parse_array(threads_str);
    free(threads_str);
    for (int i = 0; threads[i]; ++i) {
        char *tmp = decode_str(threads[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(uuid, tmp_uuid)) {
            free(tmp_uuid);
            cjson_free_array(threads);
            return tmp_obj;
        }
        free(tmp_uuid);
        cjson_free(tmp_obj);
    }
    cjson_free_array(threads);
    return NULL;
}
