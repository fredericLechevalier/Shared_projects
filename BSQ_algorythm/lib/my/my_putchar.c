/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** libmy.a
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char x)
{
    write(1, &x, 1);
}
