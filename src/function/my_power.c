/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** task04
*/

int my_power(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        return (nb * my_power(nb, p - 1));
    }
}
