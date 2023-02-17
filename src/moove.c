/*
** EPITECH PROJECT, 2022
** moove.c
** File description:
** Function : moove
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "struct_menu.h"
#include "my.h"

void verif_start(a_i *air_info, int n)
{
    int t = sfClock_getElapsedTime(air_info->start).microseconds;
    double seconds = 1000000;
    if (air_info->start_on[n] == true)
        return;
    if (t > seconds * air_info->delay[n])
        air_info->start_on[n] = true;
}

void moove_suite(a_i *air_info, int n)
{
    if (air_info->sens_x[n] == true && air_info->sens_y[n] == true &&
        air_info->pos_x[n] >= air_info->arriv_x[n] && air_info->pos_x[n]
        >= air_info->arriv_x[n])
        cas_arriv(n, air_info);
    if (air_info->sens_x[n] == false && air_info->sens_y[n] == true &&
        air_info->pos_x[n] <= air_info->arriv_x[n] && air_info->pos_y[n]
        >= air_info->arriv_y[n])
        cas_arriv(n, air_info);
    if (air_info->sens_x[n] == true && air_info->sens_y[n] == false &&
        air_info->pos_x[n] >= air_info->arriv_x[n] && air_info->pos_y[n]
        <= air_info->arriv_y[n]) {
        cas_arriv(n, air_info);
    }
    if (air_info->sens_x[n] == false && air_info->sens_y[n] == false &&
        air_info->pos_x[n] <= air_info->arriv_x[n] && air_info->pos_x[n]
        <= air_info->arriv_x[n])
        cas_arriv(n, air_info);
}

void moove(a_i *air_info)
{
    int t = sfClock_getElapsedTime(air_info->time).microseconds;
    double seconds = 1000000;
    if (t < seconds / 100)
        return;
    sfClock_restart(air_info->time);
    for (int n = 0; n < air_info->nb; n++) {
        if (air_info->start_on[n] == true) {
            air_info->pos_x[n] += air_info->vitesse_x[n] / 100;
            air_info->pos_y[n] += air_info->vitesse_y[n] / 100;
        }
    }
    for (int n = 0; n < air_info->nb; n++) {
        verif_start(air_info, n);
        sfVector2f pos = {air_info->pos_x[n], air_info->pos_y[n]};
        air_info->hitbox[n]->left = air_info->pos_x[n];
        air_info->hitbox[n]->top = air_info->pos_y[n];
        sfSprite_setPosition(air_info->sprite[n], pos);
        sfRectangleShape_setPosition(air_info->rectangle[n], pos);
        moove_suite(air_info, n);
    }
}
