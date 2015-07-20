##
## Makefile for Makefile in /home/frayss_c/rendu/MUL_2013_wolf3d
## 
## Made by frayss_c
## Login   <frayss_c@epitech.net>
## 
## Started on  Sun Jan 12 23:07:56 2014 frayss_c
## Last update Sun Jun  8 21:53:16 2014 
##

SRC     = ./inter/sphere.c\
	  ./inter/plan.c\
	  ./inter/cylinder.c\
	  ./lib/functions.c \
	  ./lib/my_getnbr.c \
	  ./lib/my_putnbr.c \
	  ./lib/my_strncmp.c \
	  ./lib/my_str_to_wordtab.c \
	  ./light/light.c \
	  ./light/set_lum_vector.c \
	  ./light/shadow.c \
	  ./move/trans.c \
	  ./move/rotate_unrotate.c \
	  ./move/rotation_xyz.c \
	  ./move/rotation_xlylzl.c \
	  ./parser/epur_str.c \
	  ./parser/get_eye.c \
	  ./parser/get_light.c \
	  ./parser/get_name.c \
	  ./parser/get_object.c \
	  ./parser/parser.c \
	  ./parser/put_error.c \
	  ./src/error.c \
	  ./src/gerekey.c \
	  ./src/rtv1.c

NAME    = a.out

OBJ     = $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra

LIBX    = -L /usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include/ -lm -ljpeg

CC	= gcc -g3

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
