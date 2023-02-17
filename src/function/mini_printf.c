/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** day 14/15
*/

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

int recherch_type(const char *format, int num_n, va_list *i, int *nb_chara)
{
    if (format[num_n] == '%' && (format[num_n + 1] == 'd' ||
        format[num_n + 1] == 'i')) {
        *nb_chara += my_put_nbr(va_arg(*i, int));
        return 1;
    } if (format[num_n] == '%' && format[num_n + 1] == 's') {
        *nb_chara += my_putstr(va_arg(*i, char *));
        return 1;
    } if (format[num_n] == '%' && format[num_n + 1] == 'c') {
        my_putchar(va_arg(*i, int));
        *nb_chara += 1;
        return 1;
    } if (format[num_n] == '%' && format[num_n + 1] == '%') {
        my_putchar('%');
        *nb_chara += 1;
        return 1;
    } else
        return 0;
}

int mini_printf(const char *format, ...)
{
    int nb_chara = 0;
    va_list i;
    int n = 0;
    va_start(i, format);
    for (; format[n] != '\0'; n++) {
        if (format[n] == '%') {
            n = n + recherch_type(format, n, &i, &nb_chara);
        } else {
            my_putchar(format[n]);
            nb_chara++;
        }
    }
    va_end(i);
    return (nb_chara);
}
