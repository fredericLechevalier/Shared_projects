/*
** EPITECH PROJECT, 2020
** task02
** File description:
** project.h
*/

#include <stdarg.h>
#include <stdlib.h>

#ifndef MY_PROJ_

#define MY_PROJ_

struct Game {
    int     max_pick;
    int     lines;
    int     height;
    int     lenght;
    char    *board;
    int     line_pick;
    int     matches_pick;
    int     *matches;
    int     winner;
    int     playing;
};

void board_maker(struct Game *data);

int line_filler(struct Game *data, int y, int x);

void matches_counter(struct Game *data);

void GameLoop(struct Game *data);

void end_game(struct Game *data);

int winner_handler(struct Game *data);

int my_getline(char *str, int size);

void player_turn(struct Game *data);

void J1_turn(struct Game *data);

void J1_turn_line(struct Game *data, char *answer);

void J1_turn_matches(struct Game *data, char *answer);

void AI_turn(struct Game *data);

void map_update(struct Game *data);

int is_number(char *answer);

#endif /*MY_H_*/