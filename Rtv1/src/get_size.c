/*
** get_size.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Sat Jun  7 17:31:03 2014 kauch_j
** Last update Sun Jun  8 21:50:52 2014 kauch_j
*/

#include <string.h>
#include "pauvray.h"

int	get_size(char **tab)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<object>", 8) == 0)
        ++res;
      ++i;
    }
  return (res);
}
