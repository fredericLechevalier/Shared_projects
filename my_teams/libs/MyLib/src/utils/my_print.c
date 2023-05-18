/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static void print_buf(char *buf, int *size)
{
    if (*size != 0) {
        write(1, buf, *size);
        *size = 0;
    }
}

static void handle_buf(char c, char *buf, int *size)
{
    buf[*size] = c;
    *size += 1;
    if (*size == PRINT_BUF_SIZE)
        print_buf(buf, size);
}

static void add_arg(char *str, int *i, va_list list)
{
    if (str[*i]) {
        if (str[*i] == '%')
            write(1, "%", 1);
        if (str[*i] == 'd')
            write_int(va_arg(list, int));
        if (str[*i] == 's')
            write_str(va_arg(list, char *));
    }
}

void my_print(char *str, ...)
{
    va_list list;
    va_start(list, str);
    char *out_buf = malloc(sizeof(char) * PRINT_BUF_SIZE);
    int size = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '%') {
            ++i;
            print_buf(out_buf, &size);
            add_arg(str, &i, list);
        } else
            handle_buf(str[i], out_buf, &size);
    }
    print_buf(out_buf, &size);
    free(out_buf);
}
