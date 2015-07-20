/*
** get_object.c for get_object in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue May 27 13:35:36 2014 quach_a
** Last update Tue Jun  3 12:59:01 2014 kauch_j
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt.h"
#include "rtv1.h"

int	get_object_param_values(t_all *all, char **line_tab, int param, int nb)
{
  if (param == 0)
    {
      all->objects[nb].x = my_getnbr(line_tab[1]);
      all->objects[nb].y = my_getnbr(line_tab[2]);
      all->objects[nb].z = my_getnbr(line_tab[3]);
    }
  else if (param == 1)
    {
      all->objects[nb].xrot = my_getnbr(line_tab[1]);
      all->objects[nb].yrot = my_getnbr(line_tab[2]);
      all->objects[nb].zrot = my_getnbr(line_tab[3]);
    }
  else if (param == 2)
      all->objects[nb].bright = my_getnbr_double(line_tab[0]);
  else if (param == 3)
    all->objects[nb].ray = my_getnbr(line_tab[0]);
  else if (param == 4)
    {
      all->objects[nb].color[0] = my_getnbr(line_tab[0]);
      all->objects[nb].color[1] = my_getnbr(line_tab[1]);
      all->objects[nb].color[2] = my_getnbr(line_tab[2]);
    }
  return (0);
}

char	**create_name_list()
{
  char	**name_list;

  if ((name_list = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  name_list[0] = "<location";
  name_list[1] = "<rotation";
  name_list[2] = "<effect";
  name_list[3] = "<radius";
  name_list[4] = "<color";
  name_list[5] = NULL;
  return (name_list);
}

int	get_object_param(t_all *all, char **tab, int nb)
{
  char	**name_list;
  char	**line_tab;
  int	param;
  int	i;

  if ((name_list = create_name_list()) == NULL)
    return (put_error_int("Error : CREATE_NAME_LIST failed\n"));
  param = 0;
  while (param < 5)
    {
      i = 0;
      while (i < 8)
	{
	  if (strncmp(tab[i], name_list[param], strlen(name_list[param])) == 0)
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

char	**create_type_list()
{
  char	**type_list;

  if ((type_list = malloc(sizeof(char *) * 5)) == NULL)
    return (NULL);
  type_list[0] = "<sphere>";
  type_list[1] = "<plan>";
  type_list[2] = "<cylindre>";
  type_list[3] = "<cone>";
  type_list[4] = NULL;
  return (type_list);
}

int	get_type_object(t_all *all, char **tab, int nb)
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
	      return (0);
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
      if (strncmp(tab[i], "<object>", 8) == 0)
	{
	  get_object_param(all, tab + i, nb);
	  get_type_object(all, tab + i, nb);
	  i += 8;
	  ++nb;
	}
      ++i;
    }
  // test
  /* j = 0; */
  /* while (j < 3) */
  /*   { */
  /* j = 0; */
  /*     printf("BONJOUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUR\n"); */
  /*     printf("x %G\n", all->objects[j].x); */
  /*     printf("y %G\n", all->objects[j].y); */
  /*     printf("z %G\n", all->objects[j].z); */
  /*     printf("ray %G\n", all->objects[j].ray); */
  /*     printf("xrot %G\n", all->objects[j].xrot); */
  /*     printf("yrot %G\n", all->objects[j].yrot); */
  /*     printf("zrot %G\n", all->objects[j].zrot); */
  /*     printf("type %d\n", all->objects[j].type); */
  /*     printf("bright %G\n", all->objects[j].bright); */
  /*     printf("color R %d\n", all->objects[j].color[0]); */
  /*     printf("color G %d\n", all->objects[j].color[1]); */
  /*     printf("color B %d\n", all->objects[j].color[2]); */
  /*     j++; */
  /*   } */
  //  set_value(all);
  return (0);
}