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
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>


int my_power_rec_x(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        return (nb * my_power_rec_x(nb, p - 1));
    }
}

int my_lenint_x(int nbr)
{
    int i = 0;
    while (nbr > 0) {
        nbr = nbr / 10;
        i++;
    }
    return i;
}

char* int_pass_char(int nbr)
{
    int size_nbr = my_lenint_x(nbr);
    char *result = malloc(sizeof(char) * (size_nbr + 1));
    for (int i = 0; i < size_nbr + 1; i++)
        result[i] = 0;
    for (int n = 0; n != size_nbr; n++) {
        result[n] = (nbr / my_power_rec_x(10, size_nbr - n - 1)) % 10 + '0';
    }
    return result;
}
