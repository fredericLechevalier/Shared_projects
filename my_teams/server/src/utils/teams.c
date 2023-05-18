/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"


cjson *get_team_by_name(char *name)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    cjson_free(file);
    char **teams = cjson_parse_array(teams_str);
    free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_name = cjson_get_by_key(tmp_obj, "name");
        if (my_strcomp(name, tmp_name)) {
            free(tmp_name);
            cjson_free_array(teams);
            return tmp_obj;
        }
        free(tmp_name);
        cjson_free(tmp_obj);
    }
    cjson_free_array(teams);
    return NULL;
}

cjson *get_team(char *uuid)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    cjson_free(file);
    char **teams = cjson_parse_array(teams_str);
    free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(uuid, tmp_uuid)) {
            free(tmp_uuid);
            cjson_free_array(teams);
            return tmp_obj;
        }
        free(tmp_uuid);
        cjson_free(tmp_obj);
    }
    cjson_free_array(teams);
    return NULL;
}

char **get_team_subs(char *uuid)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    cjson_free(file);
    char **teams = cjson_parse_array(teams_str);
    free(teams_str);
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (my_strcomp(uuid, tmp_uuid)) {
            char *str_out = cjson_get_by_key(tmp_obj, "users");
            char **out = cjson_parse_array(str_out);
            free(str_out);free(tmp_uuid);
            cjson_free_array(teams);cjson_free(tmp_obj);return out;
        } free(tmp_uuid);cjson_free(tmp_obj);
    } cjson_free_array(teams);return NULL;
}
