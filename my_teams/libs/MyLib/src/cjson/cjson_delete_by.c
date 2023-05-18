/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

static void delete_obj(data *prev, data *temp, cjson *obj)
{
    free(temp->key);
    free(temp->value);
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        obj->data = temp->next;
    }
    free(temp);
    obj->lenght -= 1;
}

void cjson_delete_by_key(cjson *obj, const char *key)
{
    data *temp;
    data *prev = NULL;

    temp = obj->data;
    while (temp != NULL) {
        if (my_strcomp(key, temp->key)) {
            delete_obj(prev, temp, obj);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void cjson_delete_by_index(cjson *obj, const int index)
{
    data *temp;
    data *prev = NULL;
    int i = 0;
    bool pass = true;

    temp = obj->data;
    while (i != index) {
        if (temp->next == NULL) {
            pass = false;
            break;
        }
        ++i;
        prev = temp;
        temp = temp->next;
    }
    if (pass)
        delete_obj(prev, temp, obj);
}
