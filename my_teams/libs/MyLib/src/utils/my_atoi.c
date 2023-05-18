/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static bool get_sign(char *str, int i)
{
    if (i > 0 && str[i - 1] == '-')
        return true;
    return false;
}

static int get_the_nb(char *str, int i)
{
    bool neg = get_sign(str, i);
    int out = 0;

    for (; str[i] && str[i] <= 57 && str[i] >= 48; ++i) {
        out += str[i] - 48;
        out *= 10;
    }
    out /= 10;
    if (neg)
        out *= -1;
    return out;
}

int my_atoi(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] <= 57 && str[i] >= 48)
            return get_the_nb(str, i);
    }
    return 0;
}
