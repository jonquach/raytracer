/*
** get_light.c for get_light in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 19:29:04 2014 quach_a
** Last update Thu Jun  5 14:35:33 2014 frayss_c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

void	get_light_param_value(t_all *all, char **line_tab, int param)
{
  if (param == 0)
    {
      all->lum.x = my_getnbr(line_tab[1]);
      all->lum.y = my_getnbr(line_tab[2]);
      all->lum.z = my_getnbr(line_tab[3]);
    }
  else if (param == 1)
    {
      all->lum.color[0] = my_getnbr(line_tab[1]);
      all->lum.color[1] = my_getnbr(line_tab[2]);
      all->lum.color[2] = my_getnbr(line_tab[3]);
    }
}

char	**create_light_list()
{
  char	**light_list;

  if ((light_list = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  light_list[0] = "<location";
  light_list[1] = "<color";
  light_list[2] = NULL;
  return (light_list);
}

int	get_light_param(t_all *all, char **tab, int nb)
{
  char	**light_list;
  char	**line_tab;
  int	param;
  int	i;

  if ((light_list = create_light_list()) == NULL)
    return (put_error_int("Error : CREATE_NAME_LIST failed\n"));
  param = 0;
  while (param < 2)
    {
      i = 0;
      while (i < 4)
	{
	  if (strncmp(tab[i], light_list[param], strlen(light_list[param])) == 0)
	    {
	      if ((line_tab = my_str_to_wordtab(tab[i], " ")) == NULL)
		return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
	      get_light_param_value(all, line_tab, param);
	    }
	  ++i;
	}
      ++param;
    }
  return (0);
}

void	init_get_light(t_all *all, char **tab)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<light>", 7) == 0)
	{
	  get_light_param(all, tab + i, nb);
	  ++nb;
	}
      ++i;
    }
}