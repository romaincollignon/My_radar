/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get_nbr
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);
int mini_printf(const char *format, ...);

int	my_getnbr(char const *str)
{
    int neg = 1;
    long nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45)
            neg = neg * -1;
        if (str[i] >= 48 && str[i] <= 57)
            nb = nb * 10 + (str[i] - 48);
        nb = nb * neg;
        if (nb < -2147483648 || nb > 2147483647) {
            write(2, "Nombre trop grand dans get_nbr !\n", 33);
            return 0;
        } nb = nb * neg;
    } int result = nb * neg;
    return result;
}
