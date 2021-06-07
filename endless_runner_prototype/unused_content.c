/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** unused_content
*/

void create_score(struct Game *data)
{
    data->str->font = sfFont_createFromFile("Ressources/dejavu_font");
    sfText_setCharacterSize(data->str->text, 24);
    sfText_setStyle(data->str->text, );
    data->str->text = 
}

void create_huds(struct Game *data)
{
    create_game_over(data);
    //main menu
    create_score(data);
}

struct Str {
    unsigned long score;
    unsigned long hightscore;
    sfFont *font;
    sfText *text;
};
