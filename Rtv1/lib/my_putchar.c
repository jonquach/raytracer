/*
** my_putchar.c for my_putchar.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 23:26:23 2014 han_d
** Last update Sun Jun  8 21:46:14 2014 quach_a
*/

#include <unistd.h>
#include "pauvray.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
