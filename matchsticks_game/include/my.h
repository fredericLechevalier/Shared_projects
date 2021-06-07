/*
** EPITECH PROJECT, 2020
** task02
** File description:
** my.h
*/

#include <stdarg.h>
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

int my_strcomp(char *strA, char *strB);

char *my_int_to_str(int a);

char *my_getnbr_base(int nb, char *base);

char *my_malloc(int size, char c);

void pi(va_list list);

void pd(va_list list);

void pc(va_list list);

void ps(va_list list);

void po(va_list list);

void pper(va_list list);

void pu(va_list list);

void px(va_list list);

void pX(va_list list);

void pb(va_list list);

void pp(va_list list);

void pS(va_list list);

void my_printf(char *const str, ... );

#endif /*MY_H_*/
