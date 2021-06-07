/*
** EPITECH PROJECT, 2020
** signal_get
** File description:
** #include "project.h"
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJECT_H_

#define PROJECT_H_

struct Hud {
    int draw;
    sfSprite    *sprite;
    sfTexture   *texture;
    sfVector2f  position;
};

struct Obstacle {
    int life;
    int X_speed;
    sfSprite    *sprite;
    sfTexture   *texture;
    sfIntRect   rect;
    sfVector2f  position;
};

struct Player {
    int life;
    int Y_speed;
    int const_jump;
    sfSprite    *sprite;
    sfTexture   *texture;
    sfIntRect   rect;
    sfVector2f  position;
};

struct Background {
    sfSprite    *background_s;
    sfTexture   *background_t;
    sfIntRect    RectBG;
    sfVector2f   position;
};

struct Game {
    int restart;
    unsigned tick;
    int scrolling_speed;
    sfRenderWindow  *window;
    struct Background *BG_1;
    struct Background *BG_2;
    struct Background *BG_3;
    struct Player *P1;
    struct Obstacle *obst_1;
    struct Hud *game_over;
};

void main();

void launch_game(struct Game *data);

unsigned ticking(unsigned tick);

void create_window(struct Game *data);

void create_background(struct Game *data);

void display_my_window(struct Game *data);

void create_rectangles_bg(struct Game *data);

void update_rect_bg(struct Game *data);

void GameLoop(struct Game *data);

void check_input(struct Game *data);

void create_character(struct Game *data);

void update_character(struct Game *data);

void jumping(struct Game *data);

void create_obstacles(struct Game *data);

void update_obstacles(struct Game *data);

void collisions_check(struct Game *data);

int is_coll_between(sfIntRect RA, sfVector2f PA, sfIntRect RB, sfVector2f PB);

void create_game_over(struct Game *data);

void create_huds(struct Game *data);

void update_huds(struct Game *data);

#endif /*PROJECT_H_*/