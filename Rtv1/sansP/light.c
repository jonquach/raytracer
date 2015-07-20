/*
** light.c for light in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:33 2014 frayss_c
** Last update Sat May 31 16:52:36 2014 frayss_c
*/

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

void	my_normal(t_all *all, int obj)
{
  if (obj == 1)
    {
      all->n.nx = all->n.px /* +all->sphere.x */;
      all->n.ny = all->n.py /* + all->sphere.y */;
      all->n.nz = all->n.pz /* +all->sphere.z */;
    }
  else if (obj == 2)
    {
      all->n.nx = /* all->plan.x */0;
      all->n.ny = /* all->plan.y */0;
      all->n.nz = 100 /* + all->plan.z */;
    }
  else if (obj == 3)
    {
      all->n.nx = all->n.px /* + all->cyl.x */;
      all->n.ny = all->n.py /* + all->cyl.y */;
      all->n.nz = /* all->n.pz */0;
    }
  else if (obj == 4)
    {
      all->n.nx = all->n.px + 0/* all->lum.x; *//* all->cone.x */;
      all->n.ny = all->n.py + 0/* all->lum.y; *//*all->cone.y */;
      all->n.nz = 0 /* all->n.pz */ /* * - 100 */ /* all->lum.z; *//* all->cone.z */;
    }
}

void	my_cos(t_all *all, double k, int obj, t_object *object)
{
  translate1(object, &all->lum);
  rotatel(all, object);
  all->n.px = all->eye.x + (k * all->eye.vx);
  all->n.py = all->eye.y + (k * all->eye.vy);
  all->n.pz = all->eye.z + (k * all->eye.vz);
  my_normal(all, obj);
  object->normx = all->n.nx;
  object->normy = all->n.nx;
  object->normz = all->n.nx;
  all->n.cos = (all->n.nx * (all->lum.x - all->n.px))
    + (all->n.ny * (all->lum.y - all->n.py))
    + (all->n.nz * (all->lum.z - all->n.pz));
  /* all->n.cos = all->n.nx * all->lum.x2 + all->n.ny * all->lum.y2 */
  /*   + all->n.nz * all->lum.z2; */
  all->n.a2 = /* sqrt( */(all->lum.x - all->n.px) * (all->lum.x - all->n.px)
    + (all->lum.y - all->n.py) * (all->lum.y - all->n.py)
    + (all->lum.z - all->n.pz) * (all->lum.z - all->n.pz);//);
  //  object->z2 = sqrt(all->n.a2);
  if (all->n.cos < 0)
    all->n.cos = 0;
  else
    {
      all->n.a1 = /* sqrt( */all->n.nx * all->n.nx + all->n.ny * all->n.ny
	+ all->n.nz * all->n.nz;//);
      all->n.cos = all->n.cos / sqrt(all->n.a1 * all->n.a2);
    }
  if (object->bright == 0)
    {
      object->color_tmp[0] = all->n.cos * object->color[0];
      object->color_tmp[1] = all->n.cos * object->color[1];
      object->color_tmp[2] = all->n.cos * object->color[2];
    }
  else if (object->bright > 0)
    {
      object->color_tmp[0] = all->n.cos * (object->color[0] *
                                           (1 - object->bright) +
                                           all->lum.color[0] * object->bright);
      object->color_tmp[1] = all->n.cos * (object->color[1] *
                                           (1 - object->bright) +
                                           all->lum.color[1] * object->bright);
      object->color_tmp[2] = all->n.cos * (object->color[2] *
                                           (1 - object->bright) +
                                           all->lum.color[2] * object->bright);
    }
  /* if (object->color[0] > 255) */
  /*   object->color_tmp[0] = 255; */
  /* if (object->color_tmp[1] > 255) */
  /*   object->color_tmp[1] = 255; */
  /* if (object->color_tmp[2] > 255) */
  /*   object->color_tmp[2] = 255; */
  unrotatel(all);
  translate2(object, &all->lum);
}
