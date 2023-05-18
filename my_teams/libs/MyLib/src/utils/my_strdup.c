/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

char *my_strdup(const char *src)
{
    char *out = malloc(sizeof(char) * my_strlen(src)+ 1 );
    int i = 0;

    for (; src[i]; ++i)
        out[i] = src[i];
    out[i] = 0;
    return out;
}
