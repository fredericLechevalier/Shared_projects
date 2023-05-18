/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

int my_power(int nb, int p)
{
    int out = nb;

    if (p == 0)
        return 1;
    for (int i = 0; i < p - 1; ++i)
        out *= nb;
    return out;
}
