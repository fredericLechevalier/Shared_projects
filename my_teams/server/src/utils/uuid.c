/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

// char *gen_uuid(void)
// {
//     char *out = malloc(sizeof(char) * 37);
//     int index_out = 0;
//     for (int i = 0; i < 8; ++i, ++index_out)
//         out[index_out] = HEX[rand() % 16];
//     for (int j = 0; j < 3; ++j) {
//         out[index_out] = '-';
//         ++index_out;
//         for (int i = 0; i < 4; ++i, ++index_out)
//             out[index_out] = HEX[rand() % 16];
//     }
//     out[index_out] = '-';
//     ++index_out;
//     for (int i = 0; i < 12; ++i, ++index_out)
//         out[index_out] = HEX[rand() % 16];
//     out[index_out] = 0;
//     return out;
// }

char *gen_uuid(void)
{
    uuid_t uuid;
    uuid_generate_random(uuid);
    char *out = malloc(sizeof(char) * 37);
    uuid_unparse(uuid, out);
    uuid_clear(uuid);
    return out;
}
