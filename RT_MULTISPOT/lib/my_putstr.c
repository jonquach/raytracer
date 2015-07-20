/*
** my_putstr.c for my_putstr.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 23:26:42 2014 han_d
** Last update Sun Jun  8 21:46:32 2014 quach_a
*/

#include <unistd.h>
#include "pauvray.h"
#include "lib.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
