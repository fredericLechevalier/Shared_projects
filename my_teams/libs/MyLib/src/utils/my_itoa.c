/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static int get_size(int i)
{
    int out = 0;

    while (i > 0) {
        i /= 10;
        ++out;
    }
    return out;
}

static bool isneg(int *i)
{
    if (*i < 0) {
        *i *= -1;
        return true;
    }
    return false;
}

char *my_itoa(int i)
{
    bool neg = isneg(&i);
    char *out = malloc(sizeof(char) * get_size(i) + 1 + (neg ? 1 : 0));
    int index = 0;

    while (i > 0) {
        out[index] = (i % 10) + 48;
        ++index;
        i /= 10;
    }
    if (neg) {
        out[index] = '-';
        ++index;
    }
    out[index] = 0;
    my_revstr(out);
    return out;
}
