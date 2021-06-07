/*
** EPITECH PROJECT, 2020
** ma librairie
** File description:
** my_init_str
*/

#include "my.h"
#include <stdlib.h>

char *my_malloc(int size, char c)
{
    char *str = malloc(sizeof(char) * size);
    int x = 0;

    for (; x < size; x++)
        str[x] = c;
    if ( c != '\0')
        str[x] = '\0';
    return(str);
}