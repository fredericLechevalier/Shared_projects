/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-frederic.lechevalier
** File description:
** sokoban_ncurseslib
*/

#include "my.h"
#include "project.h"

void update_character(struct Game *data)
{
    int x = 0;
    for (; data->map->board[x] != 'A'; x++);
    data->plyr->pos = x;
    if (data->c == 67)
        move_testD(data);
    if (data->c == 68)
        move_testQ(data);
    if (data->c == 65)
        move_testZ(data);
    if (data->c == 66 )
        move_testS(data);
}

void update_window(struct Game *data)
{
    check_Os(data);
    if (check_window_stats(data) == 1) {
        clear();
        mvwprintw(stdscr, data->screen->height/2,
        data->screen->width/2 - 8, "Too small window.");
    } else {
        mvwprintw(stdscr, 0, 0, data->map->board);
        mvwprintw(stdscr, data->map->height, 0," \0");
    }
    wrefresh(stdscr);
}

void GameLoop(struct Game *data)
{
    ncurses_int(data);
    update_window(data);
    while (data->game_running == 1) {
        data->c = wgetch(stdscr);
        update_character(data);
        check_win(data);
        update_window(data);
    }
    endwin();
}

void ncurses_int(struct Game *data)
{
    initscr();
    noecho();
    cbreak();
}