/*
** EPITECH PROJECT, 2022
** periph.c
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

int periph_s(t_i *tow_info, a_i *air_info)
{
    if (tow_info->on == true) {
        tow_info->on = false;
        air_info->on = false;
        sfText_setString(tow_info->touch_s, "OFF");
        sfText_setColor(tow_info->touch_s, sfRed);
        return 1;
    }
    if (tow_info->on == false) {
        tow_info->on = true;
        air_info->on = true;
        sfText_setString(tow_info->touch_s, "ON");
        sfText_setColor(tow_info->touch_s, sfGreen);
        return 1;
    }
    return 0;
}

int periph_l(t_i *tow_info)
{
    if (tow_info->on_hitbox == true) {
        tow_info->on_hitbox = false;
        sfText_setString(tow_info->touch_l, "OFF");
        sfText_setColor(tow_info->touch_l, sfRed);
        return 1;
    }
    if (tow_info->on_hitbox == false) {
        tow_info->on_hitbox = true;
        sfText_setString(tow_info->touch_l, "ON");
        sfText_setColor(tow_info->touch_l, sfGreen);
        return 1;
    }
    return 0;
}

int cherch_perif(sfRenderWindow* w, t_i* tow_info, a_i* air_info)
{
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        if (act.type == sfEvtClosed) {
            sfRenderWindow_close(w);
            return 0;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            sfRenderWindow_close(w);
            return 0;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyS) {
            return periph_s(tow_info, air_info);
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyL) {
            return periph_l(tow_info);
        }
    } return 4;
}
