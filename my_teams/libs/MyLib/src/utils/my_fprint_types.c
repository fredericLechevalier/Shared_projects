/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

void fwrite_int(int i, int fd)
{
    char tmp;

    if (i < 0) {
        i *= -1;
        write(fd, "-", 1);
    }
    if (i > 0) {
        tmp = (i % 10) + 48;
        i /= 10;
        fwrite_int(i, fd);
        write(fd, &tmp, 1);
    }
}

void fwrite_str(char *str, int fd)
{
    write(fd, str, my_strlen(str));
}
