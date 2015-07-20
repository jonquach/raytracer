/*
** get_object.c for get_object in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 13:35:36 2014 quach_a
** Last update Sat Jun  7 14:15:18 2014 han_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

char	**create_param_list()
{
  char	**param_list;

  if ((param_list = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  param_list[0] = "<location";
  param_list[1] = "<rotation";
  param_list[2] = "<effect";
  param_list[3] = "<radius";
  param_list[4] = "<color";
  param_list[5] = NULL;
  return (param_list);
}

char	**create_type_list()
{
  char	**type_list;

  if ((type_list = malloc(sizeof(char *) * 5)) == NULL)
    return (NULL);
  type_list[0] = "<sphere>";
  type_list[1] = "<plan>";
  type_list[2] = "<cylinder>";
  type_list[3] = "<cone>";
  type_list[4] = NULL;
  return (type_list);
}

int	get_object_param(t_all *all, char **tab, int nb)
{
  char	**param_list;
  char	**line_tab;
  int	param;
  int	i;

  if ((param_list = create_param_list()) == NULL)
    return (put_error_int("Error : CREATE_PARAM_LIST failed\n"));
  param = 0;
  while (param < 5)
    {
      i = 0;
      while (i < 8)
	{
	  if (strncmp(tab[i], param_list[param], strlen(param_list[param]))
	      == 0)
	    {
	      if ((line_tab = my_str_to_wordtab(tab[i], " ")) == NULL)
		return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
	      get_object_param_values(all, line_tab, param, nb);
	    }
	  ++i;
	}
      ++param;
    }
  return (0);
}

int	get_object_type(t_all *all, char **tab, int nb)
{
  char	**type_list;
  int	param;
  int	i;

  if ((type_list = create_type_list()) == NULL)
    return (put_error_int("Error : malloc failed\n"));
  param = 0;
  while (param < 4)
    {
      i = 0;
      while (i < 2)
	{
	  if (strncmp(tab[i], type_list[param], strlen(type_list[param])) == 0)
	    {
	      all->objects[nb].type = param + 1;
	      return (param + 1);
	    }
	  ++i;
	}
      ++param;
    }
  return (0);
}

int	init_get_object(t_all *all, char **tab)
{
  int	i;
  int	nb;
  int	j;

  i = 0;
  nb = 0;
  while (tab[i])
    {
      j = 0;
      if (strncmp(tab[i], "<object>", 8) == 0)
	{
	  j = get_object_type(all, tab + i, nb);
	  get_object_param(all, tab + i, nb);
	  if (j == 1 || j == 3 || j == 4)
	    i += 8;
	  if (j == 2)
	    i += 7;
	  ++nb;
	}
      ++i;
    }
  return (0);
}
