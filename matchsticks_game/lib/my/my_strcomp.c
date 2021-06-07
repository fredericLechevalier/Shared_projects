/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** my_strcomp
*/

#include "my.h"

int my_strcomp(char *strA, char *strB)
{
    int nb = 0;
    for (; nb != my_strlen(strA); nb++)
        if (strA[nb] != strB[nb])
            return (0);
    if (strA[nb] == '\0' && strB[nb] == '\0')
        return (1);
    return (0);
}