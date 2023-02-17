/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H
    typedef struct tow_info {
        bool on;
        bool on_hitbox;
        int nb;
        int* pos_x;
        int* pos_y;
        float* size_round;
        sfSprite** sprite;
        sfCircleShape** circle;
        sfText* txt_l;
        sfText* touch_l;
        sfText* txt_s;
        sfText* touch_s;
        sfText* txt_time;
        sfText* touch_time;
    } t_i;

    typedef struct air_info {
        sfClock *time;
        sfClock *start;
        bool on;
        int nb;
        int nb_air;
        bool* start_on;
        bool* crash;
        float* pos_x;
        float* pos_y;
        bool* sens_x;
        bool* sens_y;
        int* arriv_x;
        int* arriv_y;
        float* vitesse_x;
        float* vitesse_y;
        float* speed;
        int* delay;
        sfSprite** sprite;
        sfRectangleShape** rectangle;
        sfIntRect** hitbox;
    } a_i;

#endif /* !STRUCT_MENU_H */
