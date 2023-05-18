/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

static int get_data_size(const char *src)
{
    short open_count = 0;
    int ind = 0;

    for (int i = 0; true; ++i) {
        if (!src[i])return -1;
        if ((is_char_in(src[i], KEY_CHAR) && (i > 0 && src[i - 1] > 0)) ||
        (is_char_in(src[i], KEY_CHAR) && i == 0)) {
            ++open_count;
            ++i;
        }
        if (open_count == 1)
            ++ind;
        if (open_count == 2)
            break;
    }
    return ind;
}

static char *parse_data(const char *src, int *index, int size)
{
    short open_count = 0;
    char *out = malloc(sizeof(char) * size + 1);
    int ind = 0;

    for (int i = 0; true; ++i) {
        if (!src[i]) return NULL;
        if ((is_char_in(src[i], KEY_CHAR) && (i > 0 && src[i - 1] > 0)) ||
        (is_char_in(src[i], KEY_CHAR) && i == 0)) {
            ++open_count;
            ++i;
        }
        if (open_count == 1) {
            out[ind] = get_the_char(src, &i);
            ++ind;
        }
        if (open_count == 2) {
            *index += i;out[ind] = 0;return out;
        }
    }
}

static char *get_data(const char *src, int *index)
{
    int size = get_data_size(src);
    if (size == -1)
        return NULL;
    return parse_data(src, index, size);
}

static bool get_var(const char *src, int *index, bool *next, cjson *obj)
{
    char *key;
    char *value;

    key = get_data(src + *index, index);
    if (key == NULL) {return false;}
    if (!get_next(src + *index, index, VALUE_CHAR, true)) {return false;}
    value = get_data(src + *index, index);
    if (value == NULL) {return false;}
    if (!get_next(src + *index, index, CLOSE_CHAR, false) &&
!get_next(src + *index, index, SPLIT_CHAR, false))
        return false;
    if (get_next(src + *index, index, CLOSE_CHAR, false)) *next = false;
    if (get_next(src + *index, index, SPLIT_CHAR, false)) {
        *next = true;
        get_next(src + *index, index, SPLIT_CHAR, true);
    }
    add_node(key, value, &(obj->data), false);
    free(key);
    free(value);
    return true;
}

cjson *cjson_parse_obj_str(const char *src)
{
    cjson *obj = cjson_init();
    int index = 0;
    bool next = true;

    if (!get_next(src + index, &index, OPEN_CHAR, true))
        return NULL;
    while (next) {
        if (!get_var(src, &index, &next, obj))
            return NULL;
    }
    return obj;
}
