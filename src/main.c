/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> MY_HUNTER
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

int main(int ac, char **av, char **env)
{
    int tmp_verif_file = verif_file();
    if (tmp_verif_file == 84) return 84;

    int tmp_verif = verif_basic(ac, av, env);
    if (tmp_verif == 84) return 84;

    t_i *tow_info = malloc(sizeof(t_i));
    a_i *air_info = malloc(sizeof(a_i));

    int tmp_verif_init = init_struct(av, tow_info, air_info);
    if (tmp_verif_init == 84) return 84;

    if (tow_info->nb == -84)
        return 84;
    return main_window(tow_info, air_info);
}
