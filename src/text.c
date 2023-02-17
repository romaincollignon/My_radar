/*
** EPITECH PROJECT, 2022
** text.c
** File description:
** Function :
*/

#include "struct_menu.h"
#include "my.h"

void init_txt_l(t_i *tow_info)
{
    sfText* text;
    text = sfText_create();
    sfFont* font;
    font = sfFont_createFromFile("./res/CodeNext.ttf");
    sfText_setString(text, "L :");
    sfText_setPosition(text, get_position(40, 35));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    tow_info->txt_l = text;

    sfText* touch;
    touch = sfText_create();
    sfText_setString(touch, "ON");
    sfText_setPosition(touch, get_position(85, 35));
    sfText_setFont(touch, font);
    sfText_setCharacterSize(touch, 30);
    sfText_setColor(touch, sfGreen);
    tow_info->touch_l = touch;
}

void init_txt_s(t_i *tow_info)
{
    sfText* text;
    text = sfText_create();
    sfFont* font;
    font = sfFont_createFromFile("./res/CodeNext.ttf");
    sfText_setString(text, "S :");
    sfText_setPosition(text, get_position(40, 70));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    tow_info->txt_s = text;

    sfText* touch;
    touch = sfText_create();
    sfText_setString(touch, "ON");
    sfText_setPosition(touch, get_position(85, 70));
    sfText_setFont(touch, font);
    sfText_setCharacterSize(touch, 30);
    sfText_setColor(touch, sfGreen);
    tow_info->touch_s = touch;
}

void init_txt_t(t_i *tow_info)
{
    sfText* text;
    text = sfText_create();
    sfFont* font;
    font = sfFont_createFromFile("./res/CodeNext.ttf");
    sfText_setString(text, "Second :");
    sfText_setPosition(text, get_position(40, 105));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    tow_info->txt_time = text;

    sfText* touch;
    touch = sfText_create();
    sfText_setString(touch, "0");
    sfText_setPosition(touch, get_position(190, 105));
    sfText_setFont(touch, font);
    sfText_setCharacterSize(touch, 30);
    sfText_setColor(touch, sfBlue);
    tow_info->touch_time = touch;
}

void init_txt(t_i *tow_info)
{
    init_txt_l(tow_info);
    init_txt_s(tow_info);
    init_txt_t(tow_info);
}

void calc_time(a_i *air_info, t_i *tow_info)
{
    int time = sfClock_getElapsedTime(air_info->start).microseconds;
    time = time / 1000000;
    char *time_char = int_pass_char(time);
    sfText_setString(tow_info->touch_time, time_char);
    return;
}
