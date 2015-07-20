/*
** my_cos.c for my_cos.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 22:53:16 2014 han_d
** Last update Sun Jun  8 21:57:29 2014 kauch_j
*/

#include <stdlib.h>
#include <math.h>
#include "pauvray.h"
#include "rotate.h"

void	my_cos_2(t_all *all, t_object *object, t_spobject *lum)
{
  object->color_tmp[0] = all->norm.cos * object->color[0];
  object->color_tmp[1] = all->norm.cos * object->color[1];
  object->color_tmp[2] = all->norm.cos * object->color[2];
  if (object->bright > 0)
    {
      object->color_tmp[0] = all->norm.cos *
	(object->color[0] * (1 - object->bright) + lum->color[0] *
	 object->bright);
      object->color_tmp[1] = all->norm.cos *
	(object->color[1] * (1 - object->bright) + lum->color[1] *
	 object->bright);
      object->color_tmp[2] = all->norm.cos *
	(object->color[2] * (1 - object->bright) + lum->color[2] *
	 object->bright);
    }
  if (object->check == 1)
    effect_check(all, object);
  translate2(object, lum);
  punrotate(lum);
  unrotate(lum);
}

void	my_cos(t_all *all, double k, t_object *object, t_spobject *lum)
{
  protate(lum, object);
  translate1(object, lum);
  all->norm.pointx = all->eye.x + (k * all->eye.vx);
  all->norm.pointy = all->eye.y + (k * all->eye.vy);
  all->norm.pointz = all->eye.z + (k * all->eye.vz);
  my_normal(all, object);
  lum->vx = lum->x - all->norm.pointx;
  lum->vy = lum->y - all->norm.pointy;
  lum->vz = lum->z - all->norm.pointz;
  rotate(lum, object);
  all->norm.cos = (all->norm.normx * (lum->vx)) + (all->norm.normy * (lum->vy))
    + (all->norm.normz * (lum->vz));
  all->norm.a2 = (lum->vx) * (lum->vx) + (lum->vy) * (lum->vy)
    + (lum->vz) * (lum->vz);
  if (all->norm.cos < 0)
    all->norm.cos = 0;
  else
    {
      all->norm.a1 = all->norm.normx * all->norm.normx + all->norm.normy
	* all->norm.normy + all->norm.normz * all->norm.normz;
      all->norm.cos = all->norm.cos / sqrt(all->norm.a1 * all->norm.a2);
    }
  my_cos_2(all, object, lum);
}
