/*
** EPITECH PROJECT, 2020
** test my_getnbrbase
** File description:
** my_getnbr_base
*/

#include "my.h"
#include <stdlib.h>

char *my_getnbr_base(int nb, char *base)
{
    int cptr = 0;
    int nb2 = nb;
    char *answer;
    int baselen = my_strlen(base);
    int div = 1;

    for (; div > 0; cptr++) {
    div = nb2 / baselen;
    nb2 = nb2 / baselen;
    }
    answer = malloc(sizeof(char *) * (cptr + 1));
    div = 1;

    for (int x = 0; div > 0; x++) {
        div = nb / baselen;
        answer[x] = base[nb % baselen];
        nb = nb / baselen;
    }
    my_revstr(answer);
    return (answer);
}
