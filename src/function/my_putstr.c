/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** taks02
*/
void my_putchar(char c);

int my_strlen(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n = n + 1;
    }
    return n;
}

int my_putstr(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n = n + 1;
    } for (int a = 0; str[a] != '\0'; a = a + 1 ) {
        my_putchar(str[a]);
    }
    return my_strlen(str);
}
