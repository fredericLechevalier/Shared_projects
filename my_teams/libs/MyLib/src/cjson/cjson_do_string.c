/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

char *cjson_do_string(int nb, ...)
{
    cjson *obj = cjson_init();
    va_list list;
    va_start(list, nb);
    char **obj_array = malloc(sizeof(char *) * nb * 2);
    char *out;

    if (obj_array == NULL)
        return NULL;
    for (int i = 0; i < nb * 2; ++i)
        obj_array[i] = va_arg(list, char *);
    for (int i = 0; i < nb * 2; i += 2) {
        add_node(obj_array[i], obj_array[i + 1], &(obj->data), true);
        obj->lenght += 1;
    }
    free(obj_array);
    out = cjson_get_obj_str(obj, false);
    cjson_free(obj);
    return out;
}
