/*
** get_eye.c for get_eye.c in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 22:43:49 2014 quach_a
** Last update Sat May 31 17:16:30 2014 quach_a
*/

#include <stdlib.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

int	get_eye(t_all *all, char *tab)
{
  char	**new;

  if ((new = my_str_to_wordtab(tab, " ")) == NULL)
    return (put_error_int("Error : WORDTAB failed\n"));
  all->eye.x = my_getnbr(new[1]);
  all->eye.y = my_getnbr(new[2]);
  all->eye.z = my_getnbr(new[3]);
  return (0);
}
