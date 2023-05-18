/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

bool cjson_write_file(char *path, int flags, const cjson *obj)
{
    char *obj_str = cjson_get_obj_str(obj, true);

    int out = write_file(path, obj_str, flags);

    free(obj_str);
    if (out == -1)
        return false;
    return true;
}
