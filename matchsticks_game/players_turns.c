/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-frederic.lechevalier
** File description:
** players_turns
*/

#include "my.h"
#include "project.h"

void J1_turn_matches(struct Game *data, char *answer)
{
    my_putstr("Matches: ");
    data->matches_pick = my_getline(answer,data->max_pick);
    if (is_number(answer) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        data->matches_pick = -1;
    } else if (data->matches_pick > data->max_pick) {
        my_printf("Error: you cannot remove more than ");
        my_printf("%i matches per turn\n", data->max_pick);
        data->matches_pick = -1;
    } else if (data->matches[data->line_pick - 1] < data->matches_pick) {
        my_printf("Error: not enough matches on this line\n");
        data->matches_pick = -1;
    } else if (data->matches_pick == 0) {
        my_printf("Error: you have to remove at least one match\n");
        data->matches_pick = -1;
    }
}

void J1_turn_line(struct Game *data, char *answer)
{
    my_putstr("Line: ");
    data->line_pick = my_getline(answer,data->max_pick);
    if (is_number(answer) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        data->line_pick = -1;
    } else if (data->line_pick > data->lines || data->line_pick <= 0) {
        my_putstr("Error: this line is out of range\n");
        data->line_pick = -1;
    }
}

void J1_turn(struct Game *data)
{
    data->line_pick = -1;
    data->matches_pick = -1;
    char *answer = my_malloc(data->max_pick, '\0');
    my_putstr("Your turn:\n");
    while (data->matches_pick == -1) {
        J1_turn_line(data, answer);
        if (data->line_pick != -1)
            J1_turn_matches(data, answer);
    }
    my_printf("Player removed %i match(es) from line %i\n",
    data->matches_pick, data->line_pick);
}

void AI_turn(struct Game *data)
{
    data->matches_pick = -1;
    my_putstr("AI's turn...\n");
    while (data->matches_pick == -1) {
        data->line_pick = (rand() % data->lines + 1);
        data->matches_pick = (rand () % data->max_pick + 1);
        if (data->matches[data->line_pick - 1] < data->matches_pick)
                data->matches_pick = -1;
    }
    my_printf("AI removed %i match(es) from line %i\n",
    data->matches_pick, data->line_pick);
}

void player_turn(struct Game *data)
{
    if (data->playing == 1) {
        J1_turn(data);
        data->playing = 2;
    } else {
        AI_turn(data);
        data->playing = 1;
    }
    map_update(data);
}