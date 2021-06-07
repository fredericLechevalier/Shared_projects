/*
** EPITECH PROJECT, 2020
** flags list 1
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void pi(va_list list)
{
    int nb = va_arg(list, int);

    my_putnbr(nb);
}

void pd(va_list list)
{
    int nb = va_arg(list, int);

    my_putnbr(nb);
}

void pc(va_list list)
{
    int x = va_arg(list, int);

    my_putchar(x);
}

void ps(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
}

void po(va_list list)
{
    unsigned int nb = va_arg(list, int);
    char *answer = my_getnbr_base(nb, "01234567");

    my_putstr(answer);
}
