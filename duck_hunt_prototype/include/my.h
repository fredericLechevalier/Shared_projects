/*
** EPITECH PROJECT, 2020
** task02
** File description:
** my.h
*/

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

#ifndef MY_H_

#define MY_H_

void my_putchar(char c);

int my_putnbr(int nb);

void my_putstr(char const *str);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_int_to_str(int a);

char *my_getnbr_base(int nb, char *base);

char *my_malloc(int size, char c);

struct Enemy {
    int             duck_alive;
    sfTexture       *duck_t;
    sfSprite        *duck_s;
    sfVector2f      position;
    sfIntRect       rect;
};

struct Game {
    unsigned        tick;
    sfRenderWindow  *window;
    sfSprite        *background_s;
    struct Enemy    *duck1;
};

void my_window(struct Game *data);

int my_strcomp(char *a, char *b);

void my_background(struct Game *data);

void duck_int(struct Game *data);

void update_sprite(struct Game *data);

void createEnemy (struct Game *data);

int is_coll_between(sfIntRect RA, sfVector2f PA, sfVector2i PB);

void collisions_check(struct Game *data);

#endif /*MY_H_*/
