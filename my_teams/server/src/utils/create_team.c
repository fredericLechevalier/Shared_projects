/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

cjson *create_team(char *name, char *description)
{
    char *uuid = gen_uuid();
    cjson *new_team = cjson_push(NULL, 5, "uuid", uuid, "name", name ,
    "description", description, "users", "[]", "channels", "[]"); free(uuid);
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *teams_str = cjson_get_by_key(file, "teams");
    char **teams = cjson_parse_array(teams_str);free(teams_str);
    int len = 0;
    char *tmp = cjson_get_obj_str(new_team, false);
    for (;teams[len] != NULL; ++len);
    teams = realloc(teams, sizeof(char *) * (len + 2));
    teams[len] = encode_str(tmp);free(tmp);
    teams[len + 1] = NULL;
    teams_str = cjson_stringify_array(teams);cjson_free_array(teams);
    cjson_set_by_key(file, "teams", teams_str);free(teams_str);
    cjson_write_file("server.cjson", O_CREAT | O_TRUNC , file);
    cjson_free(file);
    return new_team;
}
