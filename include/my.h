/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    #include "struct_menu.h"

    // Function :
    void cas_arriv(int a, a_i *air_info);
    void cas_crash(int a, int b, a_i *air_info);
    int mini_printf(const char *format, ...);
    int printf_credit(int tmp);
    char *my_put_nbr_modif(int nb);
    int	my_getnbr(char const *str);
    int my_power(int nb, int p);
    sfVector2f get_position(int x, int y);
    void calc_time(a_i *air_info, t_i *tow_info);
    char* int_pass_char(int nbr);

    // Init :
    int init_struct(char **av, t_i *tow_info, a_i *air_info);
    int init_plane_struct(a_i *air_info, int n, char *file);
    int init_tower_struct(t_i* tow_info, int n, char *file);
    char *read_bsq(char *av[]);
    sfSprite* init_fond(void);
    void init_tower_display(t_i *tow_info);
    void init_air_display(a_i *air_info);
    void init_air_display_2(a_i *air_info);
    void calc_vitesse(a_i *air_info, int n);
    void init_txt(t_i *tow_info);

    // Verif :
    int verif_file(void);
    int verif_basic(int ac, char **av, char **env);
    int verif_radar(t_i *tow_info, float x, float y);
    int verif_radar_suite(t_i *tow_info, float x, float y);
    int verif_file_good(char *file);

    // Print :
    int printf_error(void);
    int printf_credit(int tmp);

    // Window :
    int main_window(t_i *tow_info, a_i *air_info);
    int boucle_window(sfRenderWindow* window, t_i *tow_info, a_i *air_info);

    // Draw :
    void draw_all(sfRenderWindow *window, sfSprite* fond, t_i *tow_info,
a_i *air_info);

    // Moove :
    void moove(a_i *air_info);

    // Periph :
    int cherch_perif(sfRenderWindow* w, t_i* tow_info, a_i* air_info);

    // Function :
    sfVector2f get_position(int x, int y);
    int my_random(int min, int max);
    char *read_bsq(char *av[]);

    // Free :
    void my_free_teuse(t_i *tow_info, a_i *air_info);
    void my_free_tow(t_i *tow_info);
    void my_free_air(a_i *air_info);

#endif /* !MY_H_ */
