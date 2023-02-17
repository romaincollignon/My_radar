/*
** EPITECH PROJECT, 2022
** verif_file.c
** File description:
** verif file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>

#include <../include/struct_menu.h>
#include <../include/my.h>


int verif_file(void)
{
    char *tab[4] = {"./res/map_word.jpg", "./res/plane.png",
    "./res/tower.png", "./res/CodeNext.ttf"};
    for (int n = 0; n < 4; n++) {
        int addre_file = open(tab[n], O_RDONLY);
        if (addre_file == -1) {
            write(2, "Error File !\n", 13);
            close(addre_file);
            return 84;
        }
        close(addre_file);
    }
    return 0;
}

int verif_basic(int ac, char **av, char **env)
{
    if (!env || !env[0])
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return printf_credit(0);
    if (verif_file() == 84)
        ac = 84;
    if (ac != 2)
        return printf_error();
    return 0;
}

int verif_radar_suite(t_i *tow_info, float x, float y)
{
    for (int n = 0; n < tow_info->nb; n++) {
        float tmp_x = x - tow_info->pos_x[n];
        float tmp_y = y - tow_info->pos_y[n];
        float calc = my_power(tmp_x, 2) + my_power(tmp_y, 2);
        if (calc <= my_power(tow_info->size_round[n], 2)) {
            return 1;
        }
    }
    return 0;
}

int verif_radar(t_i *tow_info, float x, float y)
{
    if (verif_radar_suite(tow_info, x, y) == 1)
        return 1;
    if (verif_radar_suite(tow_info, x + 20, y) == 1)
        return 1;
    if (verif_radar_suite(tow_info, x, y + 20) == 1)
        return 1;
    if (verif_radar_suite(tow_info, x + 20, y + 20) == 1)
        return 1;
    return 0;
}

int verif_file_good(char *file)
{
    int tmp = 0;
    for (int n = 0; file[n] != '\0'; file++) {
        if (file[n] != '0' && file[n] != '1' && file[n] != '2' && file[n] != '3'
        && file[n] != '4' && file[n] != '5' && file[n] != '6' && file[n] != '7'
        && file[n] != '8' && file[n] != '9' && file[n] != ' ' && file[n] != '\n'
        && file[n] != '\0' && file[n] != '-' && file[n] != 'A' &&
        file[n] != 'T' && file[n] != '\t')
            tmp = 84;
    }
    if (tmp == 0) {
        return 0;
    } else {
        write(2, "Error File !\n", 13);
        return 84;
    }
}
