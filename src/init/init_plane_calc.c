/*
** EPITECH PROJECT, 2022
** init_plane_calc.c
** File description:
** Function : calc_vitesse
*/

#include "struct_menu.h"
#include "my.h"

void calc_vitesse(a_i *air_info, int n)
{
    float tmp_x = air_info->arriv_x[n] - air_info->pos_x[n];
    float tmp_y = air_info->arriv_y[n] - air_info->pos_y[n];
    float tmp_xx;
    float tmp_yy;
    if (tmp_x < 0)
        tmp_xx = tmp_x * - 1;
    else
        tmp_xx = tmp_x;
    if (tmp_y < 0)
        tmp_yy = tmp_y * - 1;
    else
        tmp_yy = tmp_y;
    float tmp = tmp_xx + tmp_yy;
    if (tmp < 0) tmp = tmp * -1;
    air_info->vitesse_x[n] = tmp_x / tmp * air_info->speed[n];
    air_info->vitesse_y[n] = tmp_y / tmp * air_info->speed[n];
}
