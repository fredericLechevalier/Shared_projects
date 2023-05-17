/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_int_to_str
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int a)
{
    char *str;
    int b = a;
    int c = 0;

    while (a != 0) {
    a = a / 10;
        ++c;
    }
    str = my_malloc(c+1, '\0');
    str[c + 1] = '\0';
    for (; b != 0; --c) {
        str[c] = (b % 10) + 48;
        b = b / 10;
    }
    return (str);
}
