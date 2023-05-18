/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

void cjson_set_by_key(cjson *obj, const char *key, const char *value)
{
    data *temp;

    temp = obj->data;
    while (temp != NULL) {
        if (my_strcomp(key, temp->key)) {
            free(temp->value);
            temp->value = encode_str(value);
            break;
        }
        temp = temp->next;
    }
}

void cjson_set_by_index(cjson *obj, const int index, const char *value)
{
    data *temp;
    int i = 0;
    bool pass = true;

    temp = obj->data;
    while (i != index) {
        if (temp->next == NULL) {
            pass = false;
            break;
        }
        ++i;
        temp = temp->next;
    }
    if (pass) {
        free(temp->value);
        temp->value = encode_str(value);
    }
}
