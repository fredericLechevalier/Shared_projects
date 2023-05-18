/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"
cjson *get_channel_by_name(char *team_uuid, char *name)
{
    cjson *team = get_team(team_uuid);
    char *channels_str = cjson_get_by_key(team, "channels");
    cjson_free(team);
    char **channels = cjson_parse_array(channels_str);
    free(channels_str);
    for (int i = 0; channels[i]; ++i) {
        char *tmp = decode_str(channels[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_name = cjson_get_by_key(tmp_obj, "name");
        if (my_strcomp(name, tmp_name)) {
            free(tmp_name);
            cjson_free_array(channels);
            return tmp_obj;
        }
        free(tmp_name);
        cjson_free(tmp_obj);
    }
    cjson_free_array(channels);
    return NULL;
}

cjson *get_channel(char *team_uuid, char *uuid)
{
    cjson *team = get_team(team_uuid);
    char *channels_str = cjson_get_by_key(team, "channels");
    cjson_free(team);
    char **channels = cjson_parse_array(channels_str);
    free(channels_str);
    for (int i = 0; channels[i]; ++i) {
        char *tmp = decode_str(channels[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(uuid, tmp_uuid)) {
            free(tmp_uuid);
            cjson_free_array(channels);
            return tmp_obj;
        }
        free(tmp_uuid);
        cjson_free(tmp_obj);
    }
    cjson_free_array(channels);
    return NULL;
}
