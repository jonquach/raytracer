/*
** get_eye.c for get_eye.c in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 22:43:49 2014 quach_a
** Last update Sun Jun  8 21:47:45 2014 kauch_j
*/

#include <stdlib.h>
#include <string.h>
#include "pauvray.h"
#include "lib.h"

int	get_eye_rotation(t_all *all, char **tab)
{
  char	**new;

  if (strncmp(tab[0], "<rotation", 9) != 0)
    return (-1);
  else
    {
      if ((new = my_str_to_wordtab(tab[0], " ")) == NULL)
	return (put_error_int("Error : WORDTAB failed\n"));
      all->eye.xrot = my_getnbr(new[1]);
      all->eye.yrot = my_getnbr(new[2]);
      all->eye.zrot = my_getnbr(new[3]);
    }
  return (0);
}

int	get_eye(t_all *all, char **tab)
{
  char	**new;

  if (strncmp(tab[0], "<location", 9) != 0)
    return (put_error_int("Error : no eye location\n"));
  else
    {
      if ((new = my_str_to_wordtab(tab[0], " ")) == NULL)
	return (put_error_int("Error : WORDTAB failed\n"));
      all->eye.x = my_getnbr(new[1]);
      all->eye.y = my_getnbr(new[2]);
      all->eye.z = my_getnbr(new[3]);
      get_eye_rotation(all, tab + 1);
      return (0);
    }
  return (0);
}
