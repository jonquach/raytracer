/*
** lib.h for lib.h in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/include
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:27:02 2014 han_d
** Last update Sun Jun  8 23:30:44 2014 frayss_c
*/

#ifndef		LIB_H_
# define	LIB_H_

void		my_putchar(char);
int		my_strlen(char *);
void		my_putstr(char *);
void		my_putnbr(int);

/*
** my_epur_str.c
*/

char		*epur_strcpy(char *, char *);
char		*epur_str(char *);

/*
** my_getnbr.c
*/

int		my_getnbr(char *);
int		go_to_nb(char *);
double		my_getnbr_double(char *);

/*
** my_str_to_wordtab.c
*/

int		find_char(char, char *);
int		nb_word(char *, char *);
char		*wordcpy(char *, char *, int);
char		**my_str_to_wordtab(char *, char *);

#endif		/* !LIB_H_ */
