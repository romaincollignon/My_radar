##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	src/function/mini_printf.c \
		src/function/my_put_nbr.c \
		src/function/my_putchar.c \
		src/function/my_putstr.c \
		src/function/my_revstr.c \
		src/function/my_getnbr.c \
		src/function/int_pass_char.c \
		src/function/my_power.c \
		src/init/init_plane.c \
		src/init/init_plane_calc.c \
		src/init/init_struct.c \
		src/init/init_tower.c \
		src/text.c \
		src/function.c \
		src/draw_all.c \
		src/periph.c \
		src/my_radar.c \
		src/print.c \
		src/verif_all.c \
		src/free_all.c \
		src/moove.c \
		src/main.c

OBJ =	$(SRC:.c=.o)

CFLAGS =  -Wall -Wextra -I ./include/ -g

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME =	my_radar

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) $(CSFMLFLAGS) -o $(NAME) -g

clean:
	rm -f $(NAME)

fclean:
	rm -f $(OBJ)

re:	fclean all

auteur:
	echo $(USER) > auteur
