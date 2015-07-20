/*
** functions.c for functions in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:34 2014 frayss_c
** Last update Thu Jun  5 15:51:19 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_putstr(char *s)
{
  if (s != NULL)
    write(1, s, my_strlen(s));
}
