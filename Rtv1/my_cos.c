/*
** my_cos.c for my_cos.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 14:54:27 2014 han_d
** Last update Sat Jun  7 14:59:57 2014 han_d
*/

#include <math.h>
#include "rtv1.h"

void	my_cos_2(t_all *all, t_object *object)
{
  if (object->bright == 0)
    {
      object->color_tmp[0] = all->n.cos * object->color[0];
      object->color_tmp[1] = all->n.cos * object->color[1];
      object->color_tmp[2] = all->n.cos * object->color[2];
    }
  else if (object->bright > 0)
    {
      object->color_tmp[0] = all->n.cos *
	(object->color[0] * (1 - object->bright)) + all->lum.color[0] *
	object->bright;
      object->color_tmp[1] = all->n.cos *
	(object->color[1] * (1 - object->bright)) + all->lum.color[1] *
	object->bright;
      object->color_tmp[2] = all->n.cos *
	(object->color[2] * (1 - object->bright)) + all->lum.color[2] *
	object->bright;
    }
  unrotatel(all);
  translate2(object, &all->lum);
}

void	my_cos(t_all *all, double k, t_object *object)
{
  translate1(object, &all->lum);
  all->n.px = all->eye.x + (k * all->eye.vx);
  all->n.py = all->eye.y + (k * all->eye.vy);
  all->n.pz = all->eye.z + (k * all->eye.vz);
  my_normal(all, object);
  object->normx = all->n.nx;
  object->normy = all->n.ny;
  object->normz = all->n.nz;
  all->lum.vx = all->lum.x - all->n.px;
  all->lum.vy = all->lum.y - all->n.py;
  all->lum.vz = all->lum.z - all->n.pz;
  rotatel(all, object);
  all->n.cos = (all->n.nx * (all->lum.vx)) + (all->n.ny * (all->lum.vy))
    + (all->n.nz * (all->lum.vz));
  all->n.a2 = (all->lum.vx) * (all->lum.vx) + (all->lum.vy) * (all->lum.vy)
    + (all->lum.vz) * (all->lum.vz);
  if (all->n.cos < 0)
    all->n.cos = 0;
  else
    {
      all->n.a1 = all->n.nx * all->n.nx + all->n.ny * all->n.ny
	+ all->n.nz * all->n.nz;
      all->n.cos = all->n.cos / sqrt(all->n.a1 * all->n.a2);
    }
  my_cos_2(all, object);
}
