/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

bool my_strcomp(const char *str_a, const char *str_b)
{
    int i = 0;

    for (; str_a[i] && str_b[i] && str_a[i] == str_b[i]; ++i);
    if (str_a[i] == 0 && str_b[i] == 0)
        return true;
    else
        return false;
}
