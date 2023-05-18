/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

char *my_strcat(char *out, char *in)
{
    int out_size = my_strlen(out) + my_strlen(in);
    char *tmp = malloc(sizeof(char) * out_size + 1);

    my_strcopy(tmp, out);
    my_strcopy(tmp + my_strlen(out), in);
    free(out);
    free(in);
    tmp[out_size] = 0;
    return tmp;
}
