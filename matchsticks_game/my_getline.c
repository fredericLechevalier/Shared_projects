/*
** EPITECH PROJECT, 2020
** RAM 1
** File description:
** my_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "project.h"

int my_getline(char *str, int size)
{
    int nbr;
    size_t buffer_size = size;
    size_t characters;
    characters = getline(&str, &buffer_size, stdin);
    nbr = my_getnbr(str);
    return (nbr);
}

int is_number(char *answer)
{
    for (int x = 0; answer[x] != '\n'; x++) {
        if ('0' > answer[x] || answer[x] > '9')
        return (0);
    }
    return (1);
}