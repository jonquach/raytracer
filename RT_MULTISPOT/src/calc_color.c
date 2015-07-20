/*
** calc_color.c for calc_color.c in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Jun  8 11:49:55 2014 frayss_c
** Last update Sun Jun  8 21:45:24 2014 kauch_j
*/

#include "pauvray.h"

void	calc_color(t_object *obj, t_all *all)
{
  obj->color_tmp[0] = all->tmp.color1 / all->nb_lights;
  obj->color_tmp[1] = all->tmp.color2 / all->nb_lights;
  obj->color_tmp[2] = all->tmp.color3 / all->nb_lights;
  if (obj->color_tmp[0] < (obj->color_tmp[0] + obj->color[0] * all->ambiance)
      && obj->color_tmp[1] < (obj->color_tmp[1] + obj->color[1] *
			      all->ambiance)
      && obj->color_tmp[2] < (obj->color_tmp[2] + obj->color[2] *
			      all->ambiance))
    {
      obj->color_tmp[0] += obj->color[0] * all->ambiance;
      if (obj->color_tmp[0] > 255)
	obj->color_tmp[0] = 255;
      obj->color_tmp[1] += obj->color[1] * all->ambiance;
      if (obj->color_tmp[1] > 255)
	obj->color_tmp[1] = 255;
      obj->color_tmp[2] += obj->color[2] * all->ambiance;
      if (obj->color_tmp[2] > 255)
	obj->color_tmp[2] = 255;
    }
}
