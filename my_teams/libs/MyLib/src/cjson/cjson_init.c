/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/cjson.h"
#include "../../includes/utils.h"

cjson *cjson_init(void)
{
    cjson *out = malloc(sizeof(cjson));
    out->data = NULL;
    out->lenght = 0;
    return out;
}
