/*
** rt.h for rt.h in /home/han_d/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Mon May 26 17:08:48 2014 han_d
** Last update Mon May 26 17:21:13 2014 han_d
*/

#ifndef	        RT_H_
# define	RT_H_

/*
** ERROR MACRO
*/

# define	MALLOC_FAIL 1

/*
** OTHER MACRO
*/

# define	READ_SIZE 4096

/*
** ./lib/*
*/

void		my_putchar(char);
int		my_putstr(char *);
void		my_putchar_error(char);
int		my_putstr_error(char *);

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

/*
** main.c (pas encore)
*/

int		main(int, char **);

#endif		/* !RT_H_ */
