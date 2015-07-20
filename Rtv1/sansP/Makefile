##
## Makefile for Makefile in /home/frayss_c/rendu/MUL_2013_wolf3d
## 
## Made by frayss_c
## Login   <frayss_c@epitech.net>
## 
## Started on  Sun Jan 12 23:07:56 2014 frayss_c
## Last update Sat May 31 17:02:12 2014 quach_a
##

SRC     = rtv1.c \
	  functions.c \
	  gerekey.c \
	  moves.c \
	  set_lum_vector.c \
	  shadow.c \
	  error.c \
	  set.c \
	  light.c \
	  trans.c \
	  inter.c \
	  set_color.c \
	  my_str_to_wordtab.c \
	  epur_str.c \
	  parser.c \
	  my_getnbr.c \
	  get_light.c \
	  get_eye.c \
	  get_name.c \
	  get_object.c \
	  put_error.c

NAME    = a.out

OBJ     = $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra

LIBX    = -L /usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include/ -lm

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
