/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static void fprint_buf(char *buf, int *size, int fd)
{
    if (*size != 0) {
        write(fd, buf, *size);
        *size = 0;
    }
}

static void fhandle_buf(char c, char *buf, int *size, int fd)
{
    buf[*size] = c;
    *size += 1;
    if (*size == FPRINT_BUF_SIZE)
        fprint_buf(buf, size, fd);
}

static void fadd_arg(char *str, int *i, va_list list, int fd)
{
    if (str[*i]) {
        if (str[*i] == '%')
            write(fd, "%", 1);
        if (str[*i] == 'd')
            fwrite_int(va_arg(list, int), fd);
        if (str[*i] == 's')
            fwrite_str(va_arg(list, char *), fd);
    }
}

void my_fprint(char *path, int flags, char *str, ...)
{
    int fd = open(path, O_WRONLY | flags, DEFAULT_MOD);
    va_list list;
    va_start(list, str);
    char *out_buf = malloc(sizeof(char) * FPRINT_BUF_SIZE);
    int size = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '%') {
            ++i;
            fprint_buf(out_buf, &size, fd);
            fadd_arg(str, &i, list, fd);
        } else
            fhandle_buf(str[i], out_buf, &size, fd);
    }
    fprint_buf(out_buf, &size, fd);
    free(out_buf);
    close(fd);
}

void my_errprint(char *str, ...)
{
    int fd = 2;
    va_list list;
    va_start(list, str);
    char *out_buf = malloc(sizeof(char) * FPRINT_BUF_SIZE);
    int size = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '%') {
            ++i;
            fprint_buf(out_buf, &size, fd);
            fadd_arg(str, &i, list, fd);
        } else
            fhandle_buf(str[i], out_buf, &size, fd);
    }
    fprint_buf(out_buf, &size, fd);
    free(out_buf);
    close(fd);
}
