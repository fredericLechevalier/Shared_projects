/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int nothing(connect_t *con)
{
    if (con->status != DO_NOTHING)
        return 0;
    return 1;
}
