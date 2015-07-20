/*
** get_ambiance.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/src
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Sun Jun  8 15:39:50 2014 kauch_j
** Last update Sun Jun  8 21:47:31 2014 kauch_j
*/

#include <string.h>
#include <stdlib.h>
#include "pauvray.h"
#include "lib.h"

int		get_ambiance(t_all *all, char *tab)
{
  char		**new;

  if (strncmp(tab, "<ambiance", 9) != 0)
    return (put_error_int("Error : no ambiance"));
  else
    {
      if ((new = my_str_to_wordtab(tab, " ")) == NULL)
	return (put_error_int("Error : WORDTAB failed\n"));
      all->ambiance = my_getnbr_double(new[1]);
      return (0);
    }
  return (0);
}
