/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-frederic.lechevalier
** File description:
** game
*/

#include "my.h"
#include "project.h"

int winner_handler(struct Game *data)
{
    for (int x = 0; data->board[x] != '\0'; x++)
        if (data->board[x] == '|')
            return (0);
    if (data->playing == 1)
        return (1);
    if (data->playing == 2)
        return (2);
}

void end_game(struct Game *data)
{
    if (data->winner == 2)
        my_putstr("You lost, too bad...\n");
    if (data->winner == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
}

void GameLoop(struct Game *data)
{
    while (data->winner == 0) {
        my_putstr(data->board);
        my_putchar('\n');
        player_turn(data);
        data->winner = winner_handler(data);
    }
    my_putstr(data->board);
    end_game(data);
}