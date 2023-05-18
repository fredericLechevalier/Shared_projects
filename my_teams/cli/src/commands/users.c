/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int users(connect_t *con)
{
    if (con->status != USERS)
        return 0;
    char *array_str = cjson_get_by_key(con->res, "data");
    char **array = cjson_parse_array(array_str);
    free(array_str);
    char *tmp_user_str;
    cjson *tmp_user; char *tmp_uuid; char *tmp_username; char *tmp_status;
    for (int i = 0; array[i]; ++i) {
        tmp_user_str = decode_str(array[i]);
        tmp_user = cjson_parse_obj_str(tmp_user_str);
        free(tmp_user_str);
        tmp_uuid = cjson_get_by_key(tmp_user, "uuid");
        tmp_username = cjson_get_by_key(tmp_user, "username");
        tmp_status = cjson_get_by_key(tmp_user, "status");
        client_print_users(tmp_uuid, tmp_username, atoi(tmp_status));
        free(tmp_uuid); free(tmp_username); free(tmp_status);
        cjson_free(tmp_user);
    }
    cjson_free_array(array);
    return 1;
}
