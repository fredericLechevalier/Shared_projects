/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

cjson *cjson_read_file(const char *path, int buf)
{
    char *out = read_file(path, buf);
    cjson *obj_out;

    if (out == NULL)
        return NULL;
    obj_out = cjson_parse_obj_str(out);
    free(out);
    if (obj_out == NULL)
        return NULL;
    return obj_out;
}
