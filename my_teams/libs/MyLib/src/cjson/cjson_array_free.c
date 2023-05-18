/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

void cjson_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
}
