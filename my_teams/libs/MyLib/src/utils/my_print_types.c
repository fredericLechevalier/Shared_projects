/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

void write_int(int i)
{
    char tmp;

    if (i < 0) {
        i *= -1;
        write(1, "-", 1);
    }
    if (i > 0) {
        tmp = (i % 10) + 48;
        i /= 10;
        write_int(i);
        write(1, &tmp, 1);
    }
}

void write_str(char *str)
{
    write(1, str, my_strlen(str));
}
