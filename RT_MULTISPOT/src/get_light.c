/*
** get_light.c for get_light in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 19:29:04 2014 quach_a
** Last update Sun Jun  8 22:21:42 2014 kauch_j
*/

#include <stdlib.h>
#include <string.h>
#include "pauvray.h"
#include "lib.h"

void	get_light_param_value(t_spobject *light, char **line_tab, int param)
{
  if (param == 0)
    {
      light->x = my_getnbr(line_tab[1]);
      light->y = my_getnbr(line_tab[2]);
      light->z = my_getnbr(line_tab[3]);
    }
  else if (param == 1)
    {
      light->color[0] = my_getnbr(line_tab[1]);
      light->color[1] = my_getnbr(line_tab[2]);
      light->color[2] = my_getnbr(line_tab[3]);
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

int	get_light_param(t_spobject *light, char **tab)
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
	  if (strncmp(tab[i], light_list[param], strlen(light_list[param]))
	      == 0)
	    {
	      if ((line_tab = my_str_to_wordtab(tab[i], " ")) == NULL)
		return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
	      get_light_param_value(light, line_tab, param);
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

  i = -1;
  nb = 0;
  while (tab[++i])
    {
      if (strncmp(tab[i], "<light>", 7) == 0)
	++nb;
    }
  all->nb_lights = nb;
  if ((all->light = malloc(sizeof(t_spobject) * nb)) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  nb = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<light>", 7) == 0)
	{
	  get_light_param(&all->light[nb], tab + i);
	  ++nb;
	}
      ++i;
    }
}
