##
## Makefile for Makefile in /home/han_d/Dropbox/EPITECH PROJET/Raytracer
## 
## Made by han_d
## Login   <han_d@epitech.net>
## 
## Started on  Mon May 26 16:46:23 2014 han_d
## Last update Tue May 27 19:51:33 2014 quach_a
##

SRC	=	./lib/my_putstr.c \
		./lib/my_putstr_error.c \
		./lib/my_getnbr.c \
		epur_str.c \
		get_eye.c \
		get_name.c \
		get_light.c \
		get_object.c \
		my_str_to_wordtab.c \
		parser.c \
		put_error.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

RM	=	rm -f

CC	=	gcc -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
		$(RM) *~ \#*\#
		$(RM) ./lib/*~ ./lib/\#*\#
#		$(RM) ./xlib/*~ ./xlib/\#*\#
#		$(RM) ./src/*~ ./src/\#*\#
#		$(RM) ./include/*~ ./include/\#*\#

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
