/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

static bool is_encoded_char(char c, char *str, int index)
{
    if (c == str[index]) {
        if (index > 0 && str[index - 1] < 0) {
            return true;
        }
        if (index == 0)
            return false;
    } else {
        return true;
    }
    return false;
}

static int get_nb_slot(char *str)
{
    int nb_slot = 0;
    for (int i = 0; str[i] && is_encoded_char(']', str, i); ++i) {
        if (str[i] == ',' && ((i > 0 && str[i - 1] > 0) || i == 0))
            ++nb_slot;
    }
    ++nb_slot;
    return nb_slot;
}

static char *add_in_slot(char *str, char **out, int index_out)
{
    int length = 0;
    for (; str[length] && is_encoded_char('\"', str, length); ++length);
    out[index_out] = malloc(sizeof(char) * length + 1);
    for (int i = 0; str[i] && is_encoded_char('\"', str, i); ++i)
        out[index_out][i] = str[i];
    out[index_out][length] = 0;
    return str + length;
}

char **cjson_parse_array(char *str)
{
    char *origin = str;
    char **out;
    int start = 0;
    int nb_slot;
    int out_index = 0;

    for (;str[start] && is_encoded_char('[', str, start); ++start);
    nb_slot = get_nb_slot(str + start);
    (my_strlen(str) == 2) ? (nb_slot = 0) : (0);
    out = malloc(sizeof(char *) * (nb_slot + 1));
    if (nb_slot == 0) {
        out[0] = NULL;return out;
    }
    for (int i = start; str[i] && is_encoded_char(']', str, start); ++i) {
        if (str[i] == '\"' && str[i - 1] > 0) {
            str = add_in_slot(str + i + 1, out, out_index);
            i = 0;++out_index;
        }
    }
    out[out_index] = NULL;str = origin;return out;
}

char *cjson_stringify_array(char **array)
{
    char *out;
    int size = 0;
    int str_sizes = 0;
    int index_out = 1; int tmp = 0;
    for (; array[size] != NULL;++size)
        str_sizes += my_strlen(array[size]);
    if ((str_sizes + (size * 2) + size + 2) <= 2) tmp = 1;
    out = malloc(sizeof(char) * (str_sizes + (size * 2) + size + 2 + tmp));
    out[0] = '[';
    for (int i = 0; array[i]; ++i) {
        out[index_out] = '"';
        ++index_out;
        my_strcopy(out + index_out, array[i]);
        index_out += my_strlen(array[i]);
        my_strcopy(out + index_out, "\",");
        index_out += 2;
    }
    if (index_out <= 1) ++index_out;
    out[index_out - 1] = ']';out[index_out] = 0;
    return out;
}
