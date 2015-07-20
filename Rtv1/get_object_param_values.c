/*
** get_object_param_values.c for get_object_param_values.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 14:09:08 2014 han_d
** Last update Sat Jun  7 14:53:45 2014 han_d
*/

#include <stdio.h>
#include "rtv1.h"
#include "rt.h"

void	get_object_param_values(t_all *all, char **line_tab, int param, int nb)
{
  if (param == 0)
    {
      all->objects[nb].x = my_getnbr(line_tab[1]);
      all->objects[nb].y = my_getnbr(line_tab[2]);
      all->objects[nb].z = my_getnbr(line_tab[3]);
    }
  else if (param == 1)
    {
      all->objects[nb].xrot = my_getnbr(line_tab[1]) % 180;
      all->objects[nb].yrot = my_getnbr(line_tab[2]) % 180;
      all->objects[nb].zrot = my_getnbr(line_tab[3]) % 180;
      if (all->objects[nb].xrot >= 90)
        all->objects[nb].xrot = 180 + all->objects[nb].xrot;
      if (all->objects[nb].yrot >= 90)
        all->objects[nb].yrot = 180 + all->objects[nb].yrot;
      if (all->objects[nb].zrot >= 90)
        all->objects[nb].zrot = 180 + all->objects[nb].zrot;
    }
  else if (param == 2)
    all->objects[nb].bright = my_getnbr_double(line_tab[0]);
  else
    get_object_param_values_2(all, line_tab, param, nb);
}

void	get_object_param_values_2(t_all *all, char **line_tab, int param,
				  int nb)
{
  if (param == 3)
    {
      if (all->objects[nb].type == CONE)
        all->objects[nb].angle = my_getnbr(line_tab[0]);
      else
        all->objects[nb].ray = my_getnbr(line_tab[0]);
    }
  else if (param == 4)
    {
      all->objects[nb].color[2] = my_getnbr(line_tab[1]);
      all->objects[nb].color[1] = my_getnbr(line_tab[2]);
      all->objects[nb].color[0] = my_getnbr(line_tab[3]);
      printf("%s\n", line_tab[2]);
      printf("%d\n", all->objects[nb].color[2]);
    }
}