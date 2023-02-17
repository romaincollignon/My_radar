/*
** EPITECH PROJECT, 2022
** free_all.c
** File description:
** Function : free_air, free_tow, my_free_teuse
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "struct_menu.h"
#include "my.h"

void my_free_air(a_i *air_info)
{
    free(air_info->pos_x);
    free(air_info->pos_y);
    free(air_info->arriv_x);
    free(air_info->arriv_y);
    free(air_info->speed);
    free(air_info->delay);
    for (int n = 0; n < air_info->nb; n++) {
        sfSprite_destroy(air_info->sprite[n]);
        sfRectangleShape_destroy(air_info->rectangle[n]);
    }
    sfClock_destroy(air_info->time);
    sfClock_destroy(air_info->start);
    free(air_info->hitbox);
    free(air_info);
}

void my_free_tow(t_i *tow_info)
{
    free(tow_info->pos_x);
    free(tow_info->pos_y);
    for (int n = 0; n < tow_info->nb; n++) {
        sfSprite_destroy(tow_info->sprite[n]);
        sfCircleShape_destroy(tow_info->circle[n]);
    }
    free(tow_info);
}

void my_free_teuse(t_i *tow_info, a_i *air_info)
{
    my_free_air(air_info);
    my_free_tow(tow_info);
}
