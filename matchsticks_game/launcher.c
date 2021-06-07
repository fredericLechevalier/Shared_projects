/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-frederic.lechevalier
** File description:
** launcher
*/

#include "my.h"
#include "project.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return (84);
    struct Game *data = malloc(sizeof(struct Game));
    data->lines = my_getnbr(argv[1]);
    data->max_pick = my_getnbr(argv[2]);
    data->height = data->lines + 2;
    data->lenght = data->lines * 2 + 1;
    data->winner = 0;
    data->playing = 1;
    board_maker(data);
    GameLoop(data);
    return (data->winner);
}