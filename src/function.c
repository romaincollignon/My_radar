/*
** EPITECH PROJECT, 2022
** function.c
** File description:
** Function : get_position, read_bsq
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include "struct_menu.h"
#include "my.h"

void cas_arriv(int a, a_i *air_info)
{
    if (air_info->crash[a] == false)
        air_info->nb_air--;
    air_info->crash[a] = true;
}

void cas_crash(int a, int b, a_i *air_info)
{
    if (air_info->crash[a] == false && air_info->crash[b] == false)
        air_info->nb_air = air_info->nb_air - 2;
    air_info->crash[a] = true;
    air_info->crash[b] = true;
}

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;
    vector.y = y;
    vector.x = x;
    return vector;
}

char *read_bsq(char *av[])
{
    struct stat st;
    stat(av[1], &st);
    int adresse = open(av[1], O_RDONLY);
    if (adresse == -1) {
        close(adresse);
        return "84";
    }
    close(adresse);
    char *file = malloc(sizeof(char) * (st.st_size + 1));
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return "-84-";
    int size_file = read(fd, file, st.st_size);
    file[size_file] = '\0';
    close(fd);
    return file;
}
