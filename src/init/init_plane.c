/*
** EPITECH PROJECT, 2022
** init_plane.c
** File description:
** Function :
*/

#include "struct_menu.h"
#include "my.h"

void init_hitbox(a_i* air_info, int n)
{
    air_info->hitbox[n] = malloc(sizeof(sfFloatRect*) * air_info->nb);
    air_info->hitbox[n]->left = air_info->pos_x[n];
    air_info->hitbox[n]->top = air_info->pos_y[n];
    air_info->hitbox[n]->width = 20;
    air_info->hitbox[n]->height = 20;
}

void init_air_display_2(a_i *air_info)
{
    air_info->sprite = malloc(sizeof(sfSprite*) * air_info->nb);
    sfTexture* texture = sfTexture_createFromFile("./res/plane.png", NULL);
    air_info->hitbox = malloc(sizeof(sfFloatRect*) * air_info->nb);
    air_info->vitesse_x = malloc(sizeof(int) * air_info->nb);
    air_info->vitesse_y = malloc(sizeof(int) * air_info->nb);
    sfVector2f scale_tower = {0.075, 0.075};
    for (int n = 0; n < air_info->nb; n++) {
        calc_vitesse(air_info, n);
        sfSprite* tmp_sprite = sfSprite_create();
        sfVector2f pos_tower = {air_info->pos_x[n], air_info->pos_y[n]};
        sfSprite_setTexture(tmp_sprite, texture, sfTrue);
        sfSprite_setPosition(tmp_sprite, pos_tower);
        sfSprite_setScale(tmp_sprite, scale_tower);
        air_info->sprite[n] = tmp_sprite;
        init_hitbox(air_info, n);
    }
}

void init_air_display(a_i *air_info)
{
    air_info->rectangle = malloc(sizeof(sfRectangleShape*) * air_info->nb);
    sfVector2f size = {20, 20};
    for (int n = 0; n < air_info->nb; n++){
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(rectangle, get_position(air_info->pos_x[n],
        air_info->pos_y[n]));
        sfRectangleShape_setFillColor(rectangle, sfTransparent);
        sfRectangleShape_setOutlineThickness(rectangle, (float)1);
        sfRectangleShape_setOutlineColor(rectangle, sfWhite);
        sfRectangleShape_setSize(rectangle, size);
        air_info->rectangle[n] = rectangle;
    }
    init_air_display_2(air_info);
}

void charging_plane(a_i *air_info, int pos, char *tmp)
{
    if (pos == 1) {
        air_info->pos_x[air_info->nb] = my_getnbr(tmp);
    } if (pos == 2) {
        air_info->pos_y[air_info->nb] = my_getnbr(tmp);
    } if (pos == 3) {
        air_info->arriv_x[air_info->nb] = my_getnbr(tmp);
    } if (pos == 4) {
        air_info->arriv_y[air_info->nb] = my_getnbr(tmp);
    } if (pos == 5) {
        air_info->speed[air_info->nb] = my_getnbr(tmp);
    } if (pos == 6) {
        air_info->delay[air_info->nb] = my_getnbr(tmp);
        if (air_info->delay[air_info->nb] == 0)
            air_info->start_on[air_info->nb] = true;
        else
            air_info->start_on[air_info->nb] = false;
        air_info->nb++;
        air_info->nb_air++;
    }
}

int init_plane_struct(a_i *air_info, int n, char *file)
{
    char *tmp = malloc(sizeof(char) * 100);
    int pos = 1;
    int a = 0;
    for (n = n + 2; file[n - 1] != '\n' && file[n - 1] != '\0' && file[n - 1]
    != 'A' && file[n - 1] != 'T'; n++) {
        while ((file[n] == ' ' && file[n + 1] == ' ') || (file[n] == '\t' &&
        file[n + 1] == '\t')) n++;
        if (file[n] == ' ' || file[n] == '\n' || file[n] == '\0' || file[n] ==
        '\t') {
            tmp[a] = '\0';
            charging_plane(air_info, pos, tmp);
            pos++;
            tmp = malloc(sizeof(char) * 100);
            a = 0;
            n++;
        } tmp[a] = file[n];
        a++;
    }
    return pos;
}
