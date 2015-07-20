/*
** set_lum_vector.c for lum_vector in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Thu May 29 14:46:32 2014 frayss_c
** Last update Thu Jun  5 17:46:22 2014 frayss_c
*/

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

void		calc_lum_vector(t_all *all, t_object *object)
{
  int           i;

  translate1(object, &all->lum);
  rotatel(all, object);
  all->lum.vx = all->lum.x - all->n.px;
  all->lum.vy = all->lum.y - all->n.py;
  all->lum.vz = all->lum.z - all->n.pz;
  unrotatel(all);
  translate2(object, &all->lum);
  i = 0;
  while (all->objects[i].type)
      {
	if (all->objects[i].type == SPHERE)
	  if (inter_sphere_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == PLAN)
	  if (inter_plan_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == CYLINDER)
	  if (inter_cyl_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == CONE)
	  if (inter_cone_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	i++;
      }
}
