/*
** EPITECH PROJECT, 2020
** flags list 2
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void pper(va_list list)
{
    my_putchar('%');
}

void pu(va_list list)
{
    unsigned int nb = va_arg(list, int);
    char *answer = my_getnbr_base(nb, "0123456789");

    my_putstr(answer);
}

void px(va_list list)
{
    unsigned int nb = va_arg(list, int);
    char *answer = my_getnbr_base(nb, "0123456789abcdef");

    my_putstr(answer);
}

void pX(va_list list)
{
    unsigned int nb = va_arg(list, int);
    char *answer = my_getnbr_base(nb, "0123456789ABCDEF");

    my_putstr(answer);
}

void pb(va_list list)
{
    unsigned int nb = va_arg(list, int);
    char *answer = my_getnbr_base(nb, "01");

    my_putstr(answer);
}