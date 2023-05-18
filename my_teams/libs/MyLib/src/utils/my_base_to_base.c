/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static char *my_dec_to_base(int in, int base)
{
    char *out = malloc(sizeof(char));
    char *tmp;
    int index = 0;

    out[0] = 0;
    while (in / base != 0) {
        tmp = my_strdup(out);
        free(out);
        out = malloc(sizeof(char) * my_strlen(tmp) + 3);
        my_strcopy(out, tmp);
        free(tmp);
        out[index] = DIGITS[(in % base)];
        out[index + 1] = 0;
        in = in / base;
        ++index;
    }
    out[index] = (in % base) + 48;
    out[index + 1] = 0;
    my_revstr(out);
    return out;
}

static int my_base_to_dec(char *in, int base)
{
    int out = 0;
    int len = my_strlen(in) - 1;

    for (int i = 0; in[i]; ++i) {
        out += my_index_of_char(DIGITS, in[i]) * my_power(base, len);
        --len;
    }
    return out;
}

char *my_base_changer(char *in, int in_base, int out_base)
{
    int dec = my_base_to_dec((in[0] == '-' ? in + 1 : in), in_base);
    char *out;
    char *tmp;

    out = my_dec_to_base(dec, out_base);
    if (in[0] == '-') {
        tmp = my_strdup(out);
        free(out);
        out = malloc(sizeof(char) * my_strlen(tmp) + 2);
        out[0] = '-';
        my_strcopy(out + 1, tmp);
        free(tmp);
    }
    free(in);
    return out;
}
