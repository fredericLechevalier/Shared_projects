/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

static int add_data(char *out, char *data, int index)
{
    out[index] = OPEN_VALUE_CHAR[0];
    ++index;
    for (int i = 0; data[i]; ++i) {
        out[index] = data[i];
        ++index;
    }
    out[index] = CLOSE_VALUE_CHAR[0];
    ++index;
    return index;
}

static void add_end_line(int *index, char *out, bool pretty, int i)
{
    if (i != 0) {
        out[*index] = SPLIT_CHAR[0];
        *index += 1;
    }
    if (pretty) {
        out[*index] = '\n';
        *index += 1;
        out[*index] = ' ';
        *index += 1;
        out[*index] = ' ';
        *index += 1;
        out[*index] = ' ';
        *index += 1;
        out[*index] = ' ';
        *index += 1;
    }
}

static char *build_string(char *out, const data *temp, bool pretty, int i)
{
    char *cp_out = my_strdup(out);
    int size_out = my_strlen(out);
    int size = size_out + my_strlen(temp->key) + my_strlen(temp->value) + 6;
    int index = size_out;

    if (pretty)
        size += 5;
    free(out);
    out = malloc(sizeof(char) * size + 1);
    my_strcopy(out, cp_out);
    free(cp_out);
    add_end_line(&index, out, pretty, i);
    index = add_data(out, temp->key, index);
    out[index] = VALUE_CHAR[0];
    ++index;
    index = add_data(out, temp->value, index);
    out[index] = 0;
    return out;
}

static char *end(char *out, bool pretty)
{
    char *pretty_end_tmp;
    int tmp;

    pretty_end_tmp = my_strdup(out);
        free(out);
        tmp = my_strlen(pretty_end_tmp);
        out = malloc(sizeof(char) * tmp + 4);
        my_strcopy(out, pretty_end_tmp);

    if (pretty) {
        out[tmp] = '\n';
        out[tmp + 1] = CLOSE_CHAR[0];
        out[tmp + 2] = 0;
    } else {
        out[tmp] = CLOSE_CHAR[0];
        out[tmp + 1] = 0;
    }
    free(pretty_end_tmp);
    return out;
}

char *cjson_get_obj_str(const cjson *obj, bool pretty)
{
    const data *temp;
    char *out = malloc(sizeof(char) * 2);
    int i = 0;

    out[0] = OPEN_CHAR[0];
    out[1] = 0;
    temp = obj->data;
    while (temp != NULL) {
        out = build_string(out, temp, pretty, i);
        temp = temp->next;
        ++i;
    }
    out = end(out, pretty);
    return out;
}
