/*
** my_strlen.c for my_strlen.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 23:27:12 2014 han_d
** Last update Sun Jun  8 21:46:41 2014 quach_a
*/

#include "pauvray.h"
#include "lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
