/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-frederic.lechevalier
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void my_printf(char *const str, ... )
{
    int i = 0;
    char *flags_list = "idcso%uxXbpS";
    void (*ptr[])(va_list) = {&pi, &pd, &pc, &ps, &po, &pper, &pu, &px, &pX, &pb, &pp, &pS};
    va_list list;

    va_start(list, str);

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '%') {
            for (i = 0; flags_list[i] != str[x + 1]; i++);
            ptr[i](list);
            x++;
        } else {
            my_putchar(str[x]);
        }
    }
    va_end(list);
}
