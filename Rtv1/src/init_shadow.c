/*
** init_shadow.c for init_shadow in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Thu May 29 14:46:32 2014 frayss_c
** Last update Sun Jun  8 21:51:22 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"
#include "inter.h"

void		calc_lum_vector(t_all *all, t_object *object, int index,
				t_spobject *lum)
{
  int		i;
  int		shadow;

  i = 0;
  while (all->objects[i].type)
      {
	shadow = 0;
	if (all->objects[i].type == SPHERE && i != index)
	  shadow = inter_sphere_shadow(&all->objects[i], lum);
	if (all->objects[i].type == PLAN && i != index)
	  shadow = inter_plan_shadow(&all->objects[i], lum);
	if (all->objects[i].type == CYLINDER && i != index)
	  shadow = inter_cyl_shadow(&all->objects[i], lum);
	if (all->objects[i].type == CONE && i != index)
	  shadow = inter_cone_shadow(&all->objects[i], lum);
	if (shadow == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	i++;
      }
}
