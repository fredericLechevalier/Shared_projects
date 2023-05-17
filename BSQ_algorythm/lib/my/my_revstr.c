/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** 
*/

#include "my.h"

int get_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac = carac + 1;
    return (carac);
}

char *my_evil_str(char *str)
{
    int a = 0;
    int b = get_strlen(str) - 1;
    int c;

    while (a < b) {
        c = str[a];
        str[a] = str[b] ;
        str[b] = c;
        a = a + 1;
        b = b - 1;
    }
    return (str);
}

char *my_revstr(char *str)
{
    my_evil_str(str);
    return (str);
}
