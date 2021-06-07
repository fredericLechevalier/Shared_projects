/*
** EPITECH PROJECT, 2020
** task03
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr (char const *str)
{
    int i = 0;
    long int nb = 0;
    int sign = 1;

    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (; str[i] <= 57 && str[i] >= 48; i++)
        nb = nb * 10 + (str[i] - 48);
    if (nb >= 2147483647 || nb <= -2147483648)
        return (0);
    nb = nb * sign;
    return ((int)nb);
}
