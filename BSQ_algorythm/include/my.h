/*
** EPITECH PROJECT, 2020
** task02
** File description:
** my.h
*/

#include <stdlib.h>

#ifndef MY_H_

#define MY_H_

void my_putchar(char c);

int my_putnbr(int nb);

void my_putstr(char const *str);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_int_to_str(int a);

char *my_getnbr_base(int nb, char *base);

char *my_malloc(int size, char c);

char *my_strcpy_map(char *dest, char const *src);

char *replacing(char *map, int square_size, int position);

int is_map_legit(int bytes_read,char *map, char *buffer);

#endif /*MY_H_*/
