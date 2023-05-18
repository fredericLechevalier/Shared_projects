/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "includes/server.h"

int main(void)
{

    cjson *file = cjson_push(NULL, 2, "users", "[]", "teams", "[]");
    cjson_write_file("../server.cjson", O_CREAT | O_TRUNC, file);
}
