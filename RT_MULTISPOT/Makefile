##
## Makefile for Makefile in /home/frayss_c/rendu/MUL_2013_wolf3d
## 
## Made by frayss_c
## Login   <frayss_c@epitech.net>
## 
## Started on  Sun Jan 12 23:07:56 2014 frayss_c
## Last update Sun Jun  8 23:26:44 2014 frayss_c
##

SRC     = ./lib/my_epur_str.c \
	  ./lib/my_getnbr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_putnbr.c \
	  ./lib/my_putstr.c \
	  ./lib/my_strlen.c \
	  ./lib/my_str_to_wordtab.c \
	  ./src/calc_color.c \
	  ./src/init_shadow.c \
	  ./src/create_scene.c \
	  ./src/effect_check.c \
	  ./src/gere.c \
	  ./src/get_ambiance.c \
	  ./src/get_eye.c \
	  ./src/get_light.c \
	  ./src/get_name.c \
	  ./src/get_object.c \
	  ./src/get_object_param_values.c \
	  ./src/get_size.c \
	  ./src/get_window.c \
	  ./src/init_values.c \
	  ./src/inter_cone.c \
	  ./src/inter_cylinder.c \
	  ./src/inter_plan.c \
	  ./src/inter_sphere.c \
	  ./src/mlx_error.c \
	  ./src/my_cos.c \
	  ./src/my_normal.c \
	  ./src/put_error.c \
	  ./src/rotate_eye.c \
	  ./src/rotate_unrotate.c \
	  ./src/rotation.c \
	  ./src/rotation_point.c \
	  ./src/shadow.c \
	  ./src/texture.c \
	  ./src/translate.c \
	  ./src/verif_nb_param.c \
	  ./src/main.c

NAME    = rt

OBJ     = $(SRC:.c=.o)

CFLAGS	= -I ./include

LIBX    = -L /usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include/ -lm -ljpeg

CC	= gcc

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
