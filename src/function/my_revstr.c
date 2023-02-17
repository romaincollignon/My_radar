/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** task03
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    if (my_strlen(str) == 1)
        return str;
    char a;
    char b;
    char c;
    int len = my_strlen(str) - 1;
    for (int i = 0; i <= (len / 2); i = i + 1) {
        a = str[i];
        b = str[len - i];
        c = a;
        str[i] = b;
        str[len - i] = c;
    }
    return str;
}
