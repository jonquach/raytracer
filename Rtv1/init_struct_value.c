/*
** init_struct_value.c for init_struct_value.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 13:47:40 2014 han_d
** Last update Sat Jun  7 13:59:28 2014 han_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rtv1.h"
#include "rt.h"

int	get_nb_obj(char **tab)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<object>", 8) == 0)
        ++res;
      ++i;
    }
  return (res);
}

int	get_window_size(t_all *all, char *str)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  all->my.y_size = my_getnbr(tab[1]);
  all->my.x_size = my_getnbr(tab[2]);
  return (0);
}

void	init_coord_struct(t_all *all)
{
  all->my.k_color = 0;
  all->my.x_size = 0;
  all->my.y_size = 0;
  /* all->eye.x = 0; */
  /* all->eye.y = 0; */
  /* all->eye.z = 0; */
  all->lum.x = 0;
  all->lum.y = 0;
  all->lum.z = 0;
  all->lum.color[0] = 255;
  all->lum.color[1] = 255;
  all->lum.color[2] = 255;
}

void	init_objects_struct(t_all *all, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      all->objects[i].x = 0;
      all->objects[i].k = -1;
      all->objects[i].y = 0;
      all->objects[i].z = 0;
      all->objects[i].ray = 0;
      all->objects[i].xrot = 0;
      all->objects[i].yrot = 0;
      all->objects[i].zrot = 0;
      all->objects[i].type = 0;
      all->objects[i].bright = 0;
      all->objects[i].color[0] = 0;
      all->objects[i].color[1] = 0;
      all->objects[i].color[2] = 0;
      ++i;
    }
  init_coord_struct(all);
}

int	init_value(t_all *all, char **tab)
{
  all->nb_obj = get_nb_obj(tab);
  if ((all->objects = malloc(sizeof(t_object) * all->nb_obj + 1)) == NULL)
    return (put_error_int("Error : malloc failed\n"));
  init_objects_struct(all, all->nb_obj);
  write(1, "\n", 1);
  get_window_size(all, tab[0]);
  write(1, "Z", 1);
  get_name(all, tab[1]);
  write(1, "Q", 1);
  get_eye(all, tab[3]);
  write(1, "S", 1);
  init_get_object(all, tab + 5);
  write(1, "D", 1);
  init_get_light(all, tab + 5);
  write(1, "W", 1);
  write(1, "\n", 1);
  return (0);
}
