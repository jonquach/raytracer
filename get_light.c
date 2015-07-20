/*
** get_light.c for get_light in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 19:29:04 2014 quach_a
** Last update Tue May 27 20:27:05 2014 quach_a
*/

#include <stdlib.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

void	get_light_param_value(t_all *all, char **line_tab, int param, int nb)
{
  if (param == 0)
    {
      all->lum.x = my_getnbr(line_tab[1]);
      all->lum.y = my_getnbr(line_tab[2]);
      all->lum.z = my_getnbr(line_tab[3]);
    }
  else if (param == 2)
    {
      all->lum.color[0] = my_getnbr(line_tab[1]);
      all->lum.color[1] = my_getnbr(line_tab[2]);
      all->lum.color[2] = my_getnbr(line_tab[3]);
    }
}

char	**create_light_list()
{
  char	**light_list;

  if ((light_list = malloc(sizeof(char *) * 4)) == NULL)
    return (put_error_char("Error : malloc failed\n"));
  light_list[0] = "<location";
  light_list[1] = "<intensity";
  light_list[2] = "<color";
  light_list[3] = NULL;
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
  while (param < 3)
    {
      i = 0;
      while (i < 5)
	{
	  if (strncmp(tab[i], light_list[param], strlen(light_list[param])) == 0)
	    {
	      if ((line_tab = my_str_to_wordtab(tab[i], " ")) == NULL)
		return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
	      get_light_param_value(all, line_tab, param, nb);
	    }
	  ++i;
	}
      ++param;
    }
}

void	init_get_light(t_all *all, char **tab)
{
  int	i;
  int	nb;
  int	j;

  i = 0;
  nb = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<light>", 7) == 0)
	{
	  get_light_param(all, tab + i, nb);
	  i += 7;
	  ++nb;
	}
      ++i;
    }
  printf("LUMMMMMMMIIIIIIEEEEERRREEEEE\n");
  printf("x %G\n", all->lum.x);
  printf("y %G\n", all->lum.y);
  printf("z %G\n", all->lum.z);
  printf("color 0 %d\n", all->lum.color[0]);
  printf("color 1 %d\n", all->lum.color[1]);
  printf("color 2 %d\n", all->lum.color[2]);
}
