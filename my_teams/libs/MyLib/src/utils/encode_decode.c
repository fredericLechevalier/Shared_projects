/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

char *decode_str(const char *base)
{
    char *out = malloc(sizeof(char) * (my_strlen(base) + 1));
    int index_out = 0;

    for (int i = 0; base[i]; ++i) {
        if (base[i] == -1) {
            continue;
        }
        if (base[i] < -1) {
            out[index_out] = base[i] + 1;++index_out;continue;
        }
        out[index_out] = base[i];++index_out;
    }
    out[index_out] = 0;
    return out;
}

static bool is_in(char c)
{
    for (int i = 0; ENCODE_CHARS[i]; ++i) {
        if (ENCODE_CHARS[i] == c)
            return true;
    }
    return false;
}

static int get_len(const char *str)
{
    int out = 0;
    for (int i = 0; str[i]; ++i, ++out) {
        if (is_in(str[i]) && ((i > 0 && str[i - 1] > 0) || i == 0))
            ++out;
    }
    return out;
}

char *encode_str(const char *str)
{
    char *out = malloc(sizeof(char) * (get_len(str) + 2));
    int index_out = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] < 0) {
            out[index_out] = str[i] - 1;++index_out;continue;
        }
        if (is_in(str[i]) && ((i > 0 && str[i - 1] > 0) || i == 0)) {
            out[index_out] = -1;out[index_out + 1] = str[i];
            index_out += 2;continue;
        }
        if (str[i] < 128) {
            out[index_out] = str[i];++index_out;
        }
    }
    out[index_out] = 0;
    return out;
}
