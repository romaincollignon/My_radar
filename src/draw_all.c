/*
** EPITECH PROJECT, 2022
** draw_all.c
** File description:
** Function :
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

void draw_touch(sfRenderWindow *window, t_i *tow_info)
{
    sfRenderWindow_drawText(window, tow_info->txt_l, NULL);
    sfRenderWindow_drawText(window, tow_info->touch_l, NULL);
    sfRenderWindow_drawText(window, tow_info->txt_s, NULL);
    sfRenderWindow_drawText(window, tow_info->touch_s, NULL);
    sfRenderWindow_drawText(window, tow_info->txt_time, NULL);
    sfRenderWindow_drawText(window, tow_info->touch_time, NULL);
}

void draw_all(sfRenderWindow *window, sfSprite* fond, t_i *tow_info,
a_i *air_info)
{
    if (!window || !fond)
        return;
    sfRenderWindow_drawSprite(window, fond, NULL);
    for (int n = 0; n < tow_info->nb; n++) {
        if (tow_info->on_hitbox == true)
            sfRenderWindow_drawCircleShape(window, tow_info->circle[n], NULL);
        if (tow_info->on == true)
            sfRenderWindow_drawSprite(window, tow_info->sprite[n], NULL);
    } for (int n = 0; n < air_info->nb; n++) {
        if (air_info->crash[n] == false && air_info->start_on[n] == true &&
        tow_info->on_hitbox == true)
            sfRenderWindow_drawRectangleShape(window, air_info->rectangle[n],
            NULL);
        if (air_info->crash[n] == false && air_info->on == true &&
        air_info->start_on[n] == true)
            sfRenderWindow_drawSprite(window, air_info->sprite[n], NULL);
    }
    draw_touch(window, tow_info);
}
