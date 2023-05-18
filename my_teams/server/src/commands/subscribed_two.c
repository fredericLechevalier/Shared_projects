/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static bool is_in(cjson *team, char *uuid)
{
    char *str_users = cjson_get_by_key(team, "users");
    char **users = cjson_parse_array(str_users);
    free(str_users);
    for (int i = 0; users[i]; ++i) {
        char *tmp = decode_str(users[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        cjson_free(tmp_obj);
        if (my_strcomp(uuid, tmp_uuid)) {
            free(tmp_uuid);
            cjson_free_array(users);
            return true;
        }
        free(tmp_uuid);
    }
    cjson_free_array(users);
    return false;
}

void list_subscirbed(client_t *client)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);char *teams_str
= cjson_get_by_key(file, "teams");cjson_free(file);char **teams =
cjson_parse_array(teams_str);free(teams_str);int len = 0; int index_out = 0;
for (; teams[len]; ++len);char **out = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; teams[i]; ++i) {
        char *tmp = decode_str(teams[i]);cjson *tmp_obj = cjson_parse_obj_str(
tmp);free(tmp);char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        if (is_in(tmp_obj, client->uuid)) {
            char *name = cjson_get_by_key(tmp_obj, "name");char *desc =
cjson_get_by_key(tmp_obj, "description");char *uuid = cjson_get_by_key(
tmp_obj, "uuid");char *str = cjson_do_string(3, "name", name, "description",
desc, "uuid", uuid);out[index_out] = encode_str(str);
            free(str);free(name);free(desc);free(uuid);++index_out;
        }free(tmp_uuid);cjson_free(tmp_obj);
    }cjson_free_array(teams);out[index_out] = NULL;
    char *out_str = cjson_stringify_array(out);cjson_free_array(out);
    client->res = cjson_push(NULL, 2, "status", STR_LIST_TEAM, "data",
    out_str);free(out_str);
}
