/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static char *add_in_team(cjson *team, cjson *new_channel)
{
    char *channels_str = cjson_get_by_key(team, "channels");
    char **channels = cjson_parse_array(channels_str);
    free(channels_str);
    int len = 0;
    for (; channels[len]; ++len);
    channels = realloc(channels, sizeof(char *) * (len + 2));
    char *new_channel_str = cjson_get_obj_str(new_channel, false);
    channels[len] = encode_str(new_channel_str);
    channels[len + 1] = NULL;
    free(new_channel_str);
    channels_str = cjson_stringify_array(channels);
    cjson_free_array(channels);
    cjson_set_by_key(team, "channels", channels_str);
    free(channels_str);
    char *team_str = cjson_get_obj_str(team, false);
    char *encoded_team = encode_str(team_str);
    free(team_str);
    return encoded_team;
}

cjson *create_channel(char *team_uuid, char *name, char *description)
{
    char *uuid = gen_uuid();
    cjson *new_channel = cjson_push(NULL, 4, "uuid", uuid, "name", name,
    "description", description, "threads", "[]");
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(tmp_uuid, team_uuid)) {
            char *new_channel_str = add_in_team(tmp_obj, new_channel);
            free(tmp_uuid);free(teams[i]);teams[i] = new_channel_str;
            cjson_free(tmp_obj);break;
        } cjson_free(tmp_obj);free(tmp_uuid);
    } teams_str = cjson_stringify_array(teams);cjson_free_array(teams);
    cjson_set_by_key(file, "teams", teams_str);free(teams_str);
    cjson_write_file("server.cjson", O_CREAT | O_TRUNC, file);
    cjson_free(file);free(uuid);return new_channel;
}
