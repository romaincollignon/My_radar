/*
** EPITECH PROJECT, 2022
** verif_file.c
** File description:
** verif file
*/

#include "struct_menu.h"
#include "my.h"

int printf_credit(int tmp)
{
    if (tmp == 0) {
        char *credit = "Air traffic simulation panel\n\nUSAGE\n  ./my_radar \
[OPTIONS] path_to_script\n  path_to_script     The path to the script file.\n\n\
OPTIONS\n  -h      print the usage and quit.\n\nUSER INTERACTIONS\n  'L' key   \
enable/disable hitboxes and areas.\n  ‘S’ key   enable/disable sprites.\n\n";
        mini_printf("Credit :\n");
        mini_printf("%s", credit);
    }
    return 0;
}

int printf_error(void)
{
    write(2, "./my_radar: bad arguments: 0 given but 84 is required\
\nretry with -h\n", 69);
    return 84;
}
