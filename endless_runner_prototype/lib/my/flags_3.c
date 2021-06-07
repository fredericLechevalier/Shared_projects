/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-frederic.lechevalier
** File description:
** flags_3
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void pp(va_list list)
{
    unsigned int nb = va_arg(list, int);

    my_putstr("0x");
    my_putstr(my_getnbr_base(nb, "0123456789abcdef"));
}

void pS(va_list list)
{
    int x = 0;
    char *str = va_arg(list, char *);

    for (x = 0; str[x] != '\0'; x++) {
        if (str[x] < 32 || 127 < str[x]) {
            my_putchar('\\');
            my_putstr(my_getnbr_base(str[x], "01234567"));
        } else {
        my_putchar(str[x]);
        }
    }
    my_putchar('\\');
    my_putstr(my_getnbr_base(str[x], "01234567"));
}