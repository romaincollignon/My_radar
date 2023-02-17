/*
** EPITECH PROJECT, 2022
** init_struct.c
** File description:
** Function :
*/

#include "struct_menu.h"
#include "my.h"

sfSprite* init_fond(void)
{
    sfTexture* texture = sfTexture_createFromFile("./res/map_word.jpg", NULL);
    sfSprite* sprite = sfSprite_create();;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

int compt_a_t(char *file, int pos)
{
    int a = 0;
    int b = 0;
    for (int n = 0; file[n] != '\0'; n++) {
        if (file[n] == 'A')
            a++;
        if (file[n] == 'T')
            b++;
    }
    if (pos == 1)
        return a;
    else
        return b;
}

void init_struct_malloc(t_i *tow_info, a_i *air_info, char *file)
{
    int a = compt_a_t(file, 1);
    int b = compt_a_t(file, 2);
    air_info->pos_x = malloc(sizeof(int) * a + 2);
    air_info->pos_y = malloc(sizeof(int) * a + 2);
    air_info->arriv_x = malloc(sizeof(int) * a + 2);
    air_info->arriv_y = malloc(sizeof(int) * a + 2);
    air_info->speed = malloc(sizeof(int) * a + 2);
    air_info->delay = malloc(sizeof(int) * a + 2);
    air_info->on = malloc(sizeof(bool) * 1 + 5);
    tow_info->pos_x = malloc(sizeof(int) * b + 2);
    tow_info->pos_y = malloc(sizeof(int) * b + 2);
    tow_info->size_round = malloc(sizeof(int) * b + 2);
    tow_info->on = malloc(sizeof(bool) * b + 2);
    air_info->crash = malloc(sizeof(bool) * a + 2);
    air_info->start_on = malloc(sizeof(bool) * a + 2);
    air_info->nb_air = 0;
}

void init_sens(a_i *air_info)
{
    sfClock* clock = sfClock_create();
    air_info->time = clock;
    sfClock* clock2 = sfClock_create();
    air_info->start = clock2;
    air_info->sens_x = malloc(sizeof(bool) * air_info->nb + 5);
    air_info->sens_y = malloc(sizeof(bool) * air_info->nb + 5);
    for (int i = 0; i < air_info->nb; i++) {
        if (air_info->arriv_x[i] - air_info->pos_x[i] >= 0)
            air_info->sens_x[i] = true;
        else
            air_info->sens_x[i] = false;
        if (air_info->arriv_y[i] - air_info->pos_y[i] >= 0)
            air_info->sens_y[i] = true;
        else
            air_info->sens_y[i] = false;
    }
    for (int i = 0; i < air_info->nb; i ++) {
        air_info->crash[i] = false;
    }
}

int init_struct(char **av, t_i *tow_info, a_i *air_info)
{
    char *file = read_bsq(av);
    if (verif_file_good(file) == 84) return 84;
    if (file[0] == '8' && file[1] == '4') {
        tow_info->nb = -84;
        return 84;
    } tow_info->on = true;
    air_info->on = true;
    tow_info->on_hitbox = true;
    tow_info->nb = 0;
    air_info->nb = 0;
    init_struct_malloc(tow_info, air_info, file);
    int tmp_a = 6;
    int tmp_t = 3;
    for (int n = 0; file[n] != '\0'; n++) {
        if (file[n] == 'A')
            tmp_a = init_plane_struct(air_info, n, file);
        if (file[n] == 'T')
            tmp_t = init_tower_struct(tow_info, n, file);
        if (tmp_a != 7 || tmp_t != 3) return 84;
    } init_sens(air_info);
    return 0;
}
