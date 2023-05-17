/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-frederic.lechevalier
** File description:
** BSQ_tools
*/

#include "include/my.h"
#include <stdio.h>

int is_map_legit(int bytes_read,char *map, char *buffer)
{
    int lines = 0;
    int x = 0;
    char *nb_line;

    for (; buffer[x] != '\n'; x++);
    nb_line = my_malloc(x+2, '\0');
    for (x = 0; buffer[x] != '\n'; x++)
        nb_line[x] = buffer[x];
    for (x = 0; map[x] != '\0'; x++)
        if (map[x] == '\n')
            lines++;
    if (lines != my_getnbr(nb_line))
        return (-1);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\n')
            return (-1);
    }
    free(nb_line);
    return (bytes_read);
}

char *replacing(char *map, int square_size, int position)
{
    int l;

    for (int x = square_size; x != 0; x--) {
        for (int y = square_size; y != 0; y--) {
        map[position] = 'x';
        position--;
        }
        for (l = 0; map[l] != '\n'; l++);
        l++;
        position = (position - l + square_size);
    }
    my_putstr(map);
}

char *my_strcpy_map(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    for (; src[a] != '\n'; a++);
    a++;
    while (src[a] != '\0') {
        dest[b] = src[a];
        a++;
        b++;
    }
    dest[a] = '\0';
    return (dest);
}