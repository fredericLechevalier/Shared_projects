/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

char ***cjson_get_obj_array(const cjson *obj)
{
    const data *temp;
    char ***out = malloc(sizeof(char **) * (obj->lenght + 1));
    int index = 0;

    for (int i = 0; i < obj->lenght; ++i)
        out[i] = malloc(sizeof(char *) * 2);
    temp = obj->data;
    while (temp != NULL) {
        out[index][0] = my_strdup(temp->key);
        out[index][1] = decode_str(temp->value);
        ++index;
        temp = temp->next;
    }
    out[obj->lenght] = NULL;
    return out;
}

void cjson_free_obj_array(char ***obj_array)
{
    for (int i = 0; obj_array[i] != NULL; ++i) {
        free(obj_array[i][0]);
        free(obj_array[i][1]);
        free(obj_array[i]);
    }
    free(obj_array);
}
