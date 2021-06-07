/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** libmy.a
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (int x = 0; str[x] != '\0'; x++)
        my_putchar(str[x]);
}
