/*
** my_putstr.c for my_putstr.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/lib
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Mon May 26 17:14:46 2014 han_d
** Last update Mon May 26 17:26:31 2014 han_d
*/

#include <stdlib.h>
#include "../include/rt.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (MALLOC_FAIL);
  while (str[i])
    {
      my_putchar(str[i]);
      ++i;
    }
}
