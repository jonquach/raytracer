/*
** rt.h for rt.h in /home/han_d/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Mon May 26 17:08:48 2014 han_d
** Last update Sat May 31 18:25:53 2014 quach_a
*/

#ifndef	        RT_H_
# define	RT_H_

#include "rtv1.h"

/*
** ERROR MACRO
*/

# define	MALLOC_FAIL 1

/*
** OTHER MACRO
*/

# define	READ_SIZE 4096

void		my_putchar(char);
int		my_putstr(char *);
/* void		my_putchar_error(char); */
/* int		my_putstr_error(char *); */

/*
** epur_str.c
*/

char		*epur_strcpt(char *, char *);
char		*epur_str(char *);

/*
** my_str_to_wordtab.c
*/

int		find_char(char, char *);
int		nb_word(char *, char *);
char		*wordcpy(char *, char *, int);
char		**my_str_to_wordtab(char *, char *);

/*
** parser.c
*/

char		*read_it(char *);

/*
** put_error.c
*/

char		*put_error_char(char *);
int		put_error_int(char *);

int		init_raytracer(t_all *);
int		my_getnbr(char *);
//double		my_getnbr_double(char *);
void		init_get_light(t_all *, char **);
int		init_get_object(t_all *, char **);
int		get_eye(t_all *, char *);
int		get_name(t_all *, char *);

#endif		/* !RT_H_ */
