/*
** EPITECH PROJECT, 2020
** task02
** File description:
** project.h
*/

#include <stdarg.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_PROJ_

#define MY_PROJ_

struct Game {
    struct Screen *screen;
    struct Map *map;
    struct Player *plyr;
    WINDOW * win;
    int game_running;
    int c;
};

struct Screen {
    int height;
    int width;
};

struct Map {
    char *board;
    char *original_board;
    int height;
    int width;
};

struct Player {
    int pos;
};

void GameLoop(struct Game *data);

void ncurses_int(struct Game *data);

int check_window_stats(struct Game *data);

char *my_strcpy_map(char *dest, char const *src);

void move_testD(struct Game *data);

void move_testQ(struct Game *data);

void move_testZ(struct Game *data);

void move_testS(struct Game *data);

void check_Os(struct Game *data);

void check_win(struct Game *data);

#endif /*MY_H_*/

