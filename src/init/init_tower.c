/*
** EPITECH PROJECT, 2022
** init_tower.c
** File description:
** Function :
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "struct_menu.h"
#include "my.h"

void init_tower_display_2(t_i *tow_info)
{
    tow_info->sprite = malloc(sizeof(sfSprite*) * tow_info->nb);
    sfTexture* texture = sfTexture_createFromFile("./res/tower.png", NULL);
    if (!texture)
        return;
    sfVector2f scale_tower = {0.15, 0.15};
    for (int n = 0; n < tow_info->nb; n++) {
        sfSprite* tmp_sprite = sfSprite_create();
        sfVector2f pos_tower = {tow_info->pos_x[n] - 38,
        tow_info->pos_y[n] - 38};
        sfSprite_setTexture(tmp_sprite, texture, sfTrue);
        sfSprite_setPosition(tmp_sprite, pos_tower);
        sfSprite_setScale(tmp_sprite, scale_tower);
        tow_info->sprite[n] = tmp_sprite;
    }
}

void init_tower_display(t_i *tow_info)
{

    tow_info->circle = malloc(sizeof(sfCircleShape*) * tow_info->nb);
    for (int n = 0; n < tow_info->nb; n++){
        sfCircleShape* circle = sfCircleShape_create();
        sfCircleShape_setPosition(circle, get_position(tow_info->pos_x[n]
        - (int)(tow_info->size_round[n]),
        tow_info->pos_y[n] - (int)(tow_info->size_round[n])));
        sfCircleShape_setFillColor(circle, sfTransparent);
        sfCircleShape_setOutlineThickness(circle, (float)3);
        sfCircleShape_setOutlineColor(circle, sfWhite);
        sfCircleShape_setRadius(circle, tow_info->size_round[n]);
        tow_info->circle[n] = circle;
    }
    init_tower_display_2(tow_info);
}

int charging_tower(t_i *tow_info, int pos, char *tmp)
{
    if (pos == 1) {
        tow_info->pos_x[tow_info->nb] = my_getnbr(tmp);
    } if (pos == 2) {
        tow_info->pos_y[tow_info->nb] = my_getnbr(tmp);
    } if (pos == 3) {
        int a = my_getnbr(tmp);
        a = a * 10;
        tow_info->size_round[tow_info->nb] = a;
        tow_info->nb++;
    }
    return 1;
}

int init_tower_struct(t_i* tow_info, int n, char *file)
{
    char *tmp = malloc(sizeof(char) * 100);
    n = n + 2;
    int pos = 1;
    for (int a = 0; file[n] != '\n' && file[n] != '\0' && file[n] != 'A' &&
    file[n] != 'T'; n++) {
        while ((file[n] == ' ' && file[n + 1] == ' ') || (file[n] == '\t' &&
        file[n + 1] == '\t')) n++;
        if (file[n] == ' ' || file[n] == '\n') {
            tmp[a] = '\0';
            pos = pos + charging_tower(tow_info, pos, tmp);
            free(tmp);
            tmp = malloc(sizeof(char) * 100);
            a = 0; n++;
        } if (file[n + 1] == '\n' || file[n + 1] == '\0') {
            tmp[a + 1] = file[n];
            tmp[a + 2] = '\0';
            charging_tower(tow_info, pos, tmp);
        } tmp[a] = file[n];
        a++;
    } return pos;
}
