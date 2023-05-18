/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static cjson *init_user(char *username)
{
    char *user_uuid = gen_uuid();
    cjson *out = cjson_push(NULL, 2, "username", username, "uuid", user_uuid,
    "messages", "[]");
    free(user_uuid);
    return out;
}

cjson *create_user(char *username)
{
    cjson *out = init_user(username);
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *users_str = cjson_get_by_key(file, "users");
    char **users = cjson_parse_array(users_str);free(users_str);
    int len = 0;
    char *tmp = cjson_get_obj_str(out, false);
    for (;users[len] != NULL; ++len);
    users = realloc(users, sizeof(char *) * (len + 2));
    users[len] = encode_str(tmp);free(tmp);
    users[len + 1] = NULL;
    char *array_str = cjson_stringify_array(users);cjson_free_array(users);
    cjson_set_by_key(file, "users", array_str);free(array_str);
    cjson_write_file("server.cjson", O_CREAT | O_TRUNC , file);
    cjson_free(file);
    return out;
}
