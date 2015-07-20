/*
** get_light.c for get_light in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 19:29:04 2014 quach_a
** Last update Thu Jun  5 18:09:40 2014 han_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/rt.h"
#include "../include/rtv1.h"
#include "../include/prototype.h"

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

int	get_light_param(t_all *all, char **tab)
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

  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<light>", 7) == 0)
	{
	  //	  printf("%s\n", tab[i]);
	  get_light_param(all, tab + i);
	  //i += 7;
	}
      ++i;
    }
  /* printf("LUMMMMMMMIIIIIIEEEEERRREEEEE\n"); */
  /* printf("x %G\n", all->lum.x); */
  /* printf("y %G\n", all->lum.y); */
  /* printf("z %G\n", all->lum.z); */
  /* printf("color 0 %d\n", all->lum.color[0]); */
  /* printf("color 1 %d\n", all->lum.color[1]); */
  /* printf("color 2 %d\n", all->lum.color[2]); */
}
