/*
** my_putstr_error.c for my_putstr_error.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/lib
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Mon May 26 17:21:22 2014 han_d
** Last update Mon May 26 17:26:42 2014 han_d
*/

#include <stdlib.h>
#include "../include/rt.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (MALLOC_FAIL);
  while (str[i])
    {
      my_putchar_error(str[i]);
      ++i;
    }
}
