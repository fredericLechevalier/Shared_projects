/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

int my_index_of_char(char *str, char tofind)
{
    for (int i = 0; str[i]; ++i) {
        if (tofind == str[i])
            return i;
    }
    return -1;
}

static bool comp_str(char *str, char *tofind)
{
    int j = 0;
    for (; tofind[j] && str[j]; ++j) {
        if (tofind[j] != str[j])
            return false;
    }
    if (tofind[j] == 0)
        return true;
    if (str[j] == 0)
        return false;
    return false;
}

int my_index_of_str(char *str, char *tofind)
{
    for (int i = 0; str[i]; ++i) {
        if (comp_str(str + i, tofind))
            return i;
    }
    return -1;
}
