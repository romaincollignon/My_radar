/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** task01
*/

#include <stdlib.h>

void my_putchar(char c);

int my_len_int(int str)
{
    int n = 1;
    if (str >= 0) {
        while (str > 9) {
            str = str / 10;
            n = n + 1;
        }
        return n;
    }
    n = 2;
    str = str * -1;
    while (str > 9) {
        str = str / 10;
        n = n + 1;
    }
    return n;
}

int my_lenint(int nbr)
{
    int i = 0;
    if (nbr == 0) {
        return 1;
    }
    while (nbr != 0) {
        nbr = nbr / 10;
        i++;
    }
    return i;
}

char *my_put_nbr_modif(int nb)
{
    int tmp = 0;
    int size_nbr = my_lenint(nb);
    if (nb == 0) {
        return "0";
    }
    char *result = malloc(sizeof(char) * (size_nbr + 1));
    while (nb > 0) {
        result[tmp] = (nb % 10) + '0';
        nb /= 10;
        tmp++;
    }
    result[size_nbr] = '\0';
    return result;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb > 0) {
        if (nb / 10 > 0) {
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + '0');
    }
    return my_len_int(nb);
}
