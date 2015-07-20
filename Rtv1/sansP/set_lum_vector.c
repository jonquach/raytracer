/*
** set_lum_vector.c for lum_vector in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Thu May 29 14:46:32 2014 frayss_c
** Last update Sat May 31 18:45:53 2014 quach_a
*/

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

void		calc_lum_vector(t_all *all, t_object *object)
{
  int           i;
  /* double	tmpx; */
  /* double	tmpy; */
  /* double	tmpz; */

  translate1(object, &all->lum);
  all->lum.vx = all->lum.x - all->n.px;
  all->lum.vy = all->lum.y - all->n.py;
  all->lum.vz = all->lum.z - all->n.pz;
  translate2(object, &all->lum);
  /* rotatel(all, object); */
  /* tmpx = all->lum.x2; */
  /* tmpy = all->lum.y2; */
  /* tmpz = all->lum.z2; */
  i = 0;
  while (all->objects[i].type)
      {
	if (all->objects[i].type == SPHERE && object->type != SPHERE)
	  if (inter_sphere_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == PLAN && object->type != PLAN)
	  if (inter_plan_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == CYLINDER && object->type != CYLINDER)
	  if (inter_cyl_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	if (all->objects[i].type == CONE && object->type != CONE)
	  if (inter_cone_shadow(all, &all->objects[i]) == -1)
	    {
	      object->color_tmp[0] = 0;
	      object->color_tmp[1] = 0;
	      object->color_tmp[2] = 0;
	    }
	i++;
      }
  /* all->lum.vx = tmpx; */
  /* all->lum.vy = tmpy; */
  /* all->lum.vz = tmpz; */
}
