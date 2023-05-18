/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"



void add_node(char *key, char *value, data **obj, bool encode)
{
    data *obj_tmp = malloc(sizeof(data));

    obj_tmp->key = my_strdup(key);
    if (encode)
        obj_tmp->value = encode_str(value);
    else
        obj_tmp->value = my_strdup(value);
    obj_tmp->next = *obj;
    *obj = obj_tmp;
}

bool is_char_in(char c, const char *ex)
{
    for (int i = 0; i < my_strlen(ex); ++i) {
        if (c == ex[i])
            return true;
    }
    return false;
}

bool get_next(const char *src, int *index, char *good, bool m_index)
{
    int i = 0;

    while (is_char_in(src[i], NULL_CHAR))
        ++i;
    if (!is_char_in(src[i], good))
        return false;
    if (m_index)
        *index += i + 1;
    return true;
}

char get_the_char(const char *src, int *i)
{
    char out;

    if (src[*i] == '\\') {
        ++*i;
        out = src[*i];
    } else
        out = src[*i];
    return out;
}
