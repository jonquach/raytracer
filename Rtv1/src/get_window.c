/*
** get_window.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Sat Jun  7 17:32:03 2014 kauch_j
** Last update Sun Jun  8 21:58:59 2014 quach_a
*/

#include <string.h>
#include <stdlib.h>
#include "pauvray.h"
#include "lib.h"

int	get_window(t_all *all, char *str)
{
  char	**tab;

  if (strncmp(str, "<window", 7) == 0)
    {
      if ((tab = my_str_to_wordtab(str, " ")) == NULL)
        return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
      all->my.y_size = my_getnbr(tab[1]);
      all->my.x_size = my_getnbr(tab[2]);
      return (0);
    }
  else
    return (put_error_int("Error : no window size\n"));
}
