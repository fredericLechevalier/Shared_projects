/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

cjson *get_user_by_username(char *username)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *users_str = cjson_get_by_key(file, "users");
    cjson_free(file);
    char **users = cjson_parse_array(users_str);
    free(users_str);
    char *tmp_user; cjson *tmp_user_obj; char *tmp_user_name;
    for (int i = 0; users[i] != NULL; ++i) {
        tmp_user = decode_str(users[i]);
        tmp_user_obj = cjson_parse_obj_str(tmp_user);
        free(tmp_user);
        tmp_user_name = cjson_get_by_key(tmp_user_obj, "username");
        if (my_strcomp(tmp_user_name, username)) {
            free(tmp_user_name);
            cjson_free_array(users);
            return tmp_user_obj;
        }
        free(tmp_user_name);
        cjson_free(tmp_user_obj);
    }
    cjson_free_array(users); return NULL;
}

cjson *get_user_by_uuid(char *uuid)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *users_str = cjson_get_by_key(file, "users"); cjson_free(file);
    char **users = cjson_parse_array(users_str); free(users_str);
    char *tmp_user; cjson *tmp_user_obj; char *tmp_user_name;
    for (int i = 0; users[i] != NULL; ++i) {
        tmp_user = decode_str(users[i]);
        tmp_user_obj = cjson_parse_obj_str(tmp_user);
        free(tmp_user);
        tmp_user_name = cjson_get_by_key(tmp_user_obj, "uuid");
        if (my_strcomp(tmp_user_name, uuid)) {
            free(tmp_user_name);
            cjson_free_array(users);
            return tmp_user_obj;
        }
        free(tmp_user_name);
        cjson_free(tmp_user_obj);
    }
    cjson_free_array(users);
    return NULL;
}
