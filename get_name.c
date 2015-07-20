/*
** get_name.c for get_name in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 22:31:38 2014 quach_a
** Last update Tue May 27 10:01:49 2014 kauch_j
*/

#include <stdlib.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

int	get_name(t_all *all, char *str)
{
  int	i;
  char	**tab;
  char	*name;

  i = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if ((name = malloc(sizeof(char) * strlen(tab[1]))) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  name = tab[1] + 6;
  while (name[i])
    i++;
  name[i - 1] = '\0';
  name[i - 2] = '\0';
  all->my.name = name;
  return (0);
}
