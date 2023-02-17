/*
** EPITECH PROJECT, 2022
** my_radar.c
** File description:
** Function : boucle_window, main_window
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

void verif_crash(a_i *air_info, t_i *tow_info, int a, int b)
{
    if (sfIntRect_contains(air_info->hitbox[a],
    air_info->pos_x[b], air_info->pos_y[b]) == sfTrue && verif_radar(tow_info,
    air_info->pos_x[a], air_info->pos_y[a]) == 0) {
        cas_crash(a, b, air_info);
    } if (sfIntRect_contains(air_info->hitbox[a], air_info->pos_x[b] + 20,
    air_info->pos_y[b]) == sfTrue && verif_radar(tow_info,
    air_info->pos_x[a], air_info->pos_y[a]) == 0) {
        cas_crash(a, b, air_info);
    } if (sfIntRect_contains(air_info->hitbox[a],
    air_info->pos_x[b], air_info->pos_y[b] + 20) == sfTrue && verif_radar(
    tow_info, air_info->pos_x[a], air_info->pos_y[a]) == 0) {
        cas_crash(a, b, air_info);
    } if (sfIntRect_contains(air_info->hitbox[a],
    air_info->pos_x[b] + 20, air_info->pos_y[b] + 20) == sfTrue && verif_radar(
    tow_info, air_info->pos_x[a], air_info->pos_y[a]) == 0) {
        cas_crash(a, b, air_info);
    }
}

void opti_crash(int a, int b, a_i *air_info, t_i *tow_info)
{
    if (air_info->start_on[a] == false || air_info->crash[a] == true ||
    (air_info->start_on[a] == false && air_info->crash[a] == true))
        return;
    if (air_info->start_on[b] == false || air_info->crash[b] == true ||
    (air_info->start_on[b] == false && air_info->crash[b] == true))
        return;
    int dist_x = air_info->pos_x[a] - air_info->pos_x[b];
    int dist_y = air_info->pos_y[a] - air_info->pos_y[b];
    if (dist_x < 50 && dist_x > -50 && dist_y < 50 && dist_y > -50)
        verif_crash(air_info, tow_info, a, b);
}

void crash(a_i *air_info, t_i *tow_info)
{
    for (int a = 0; a < air_info->nb; a++) {
        for (int b = a + 1; b < air_info->nb; b++) {
            opti_crash(a, b, air_info, tow_info);
        }
    }
}

int boucle_window(sfRenderWindow* window, t_i *tow_info, a_i *air_info)
{
    if (!window)
        return 84;
    sfSprite* fond = init_fond();
    init_air_display(air_info);
    init_tower_display(tow_info);
    init_txt(tow_info);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        moove(air_info);
        crash(air_info, tow_info);
        cherch_perif(window, tow_info, air_info);
        draw_all(window, fond, tow_info, air_info);
        sfRenderWindow_display(window);
        calc_time(air_info, tow_info);
        if (air_info->nb_air == 0)
            return 0;
    }
    return 0;
}

int main_window(t_i *tow_info, a_i *air_info)
{
    int a = boucle_window(window, tow_info, air_info);
    sfRenderWindow_destroy(window);
    my_free_teuse(tow_info, air_info);
    return a;
}
