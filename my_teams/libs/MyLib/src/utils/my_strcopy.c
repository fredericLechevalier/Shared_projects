/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

void my_strcopy(char *out, const char *src)
{
    int i = 0;
    for (; src[i]; ++i)
        out[i] = src[i];
    out[i] = 0;

}
