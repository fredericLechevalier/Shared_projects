/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

int write_file(char *path, char *str, int flags)
{
    int fd = open(path, O_WRONLY | flags, DEFAULT_MOD);
    int out;

    if (fd == -1)
        return -1;
    out = write(fd, str, my_strlen(str));
    close(fd);
    return out;
}
