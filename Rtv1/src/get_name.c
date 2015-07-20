/*
** get_name.c for get_name in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 22:31:38 2014 quach_a
** Last update Sun Jun  8 21:57:59 2014 kauch_j
*/

#include <stdlib.h>
#include <string.h>
#include "pauvray.h"
#include "lib.h"

int	get_name(t_all *all, char *str)
{
  char	**tab;
  char	*name;

  if (strncmp(str, "<scene NAME", 11) == 0)
    {
      if ((tab = my_str_to_wordtab(str, " ")) == NULL)
	return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
      if ((name = malloc(sizeof(char) * strlen(tab[1]))) == NULL)
	return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
      name = tab[1] + 6;
      all->my.name = name;
    }
  else
    return (put_error_int("Error : no window name\n"));
  return (0);
}
