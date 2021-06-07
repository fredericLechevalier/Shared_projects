/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** 
*/

#include "my.h"

int my_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac = carac + 1;
    return (carac);
}
