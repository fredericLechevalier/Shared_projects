/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

void cjson_free(cjson *obj)
{
    data *temp;

    temp = obj->data;
    while (obj->data != NULL) {
        obj->data = obj->data->next;
        free(temp->key);
        free(temp->value);
        free(temp);
        temp = obj->data;
    }
    free(obj);
}
