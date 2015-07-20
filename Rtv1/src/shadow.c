/*
** inter.c for inter in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:58 2014 frayss_c
** Last update Sun Jun  8 21:49:16 2014 quach_a
*/

#include <math.h>
#include <stdio.h>
#include "pauvray.h"
#include "inter.h"
#include "rotate.h"

int		inter_sphere_shadow(t_object *obj, t_spobject *lum)
{
  t_inter	i;

  protate(lum, obj);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  translate1(obj, lum);
  rotate(lum, obj);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  i.a = pow(lum->vx, 2) + pow(lum->vy, 2) + pow(lum->vz, 2);
  i.b = 2 * (lum->x * lum->vx + lum->y * lum->vy + lum->z * lum->vz);
  i.c = lum->x * lum->x + lum->y *
    lum->y + lum->z * lum->z - obj->ray * obj->ray;
  i.delta = i.b * i.b - 4 * i.a * i.c;
  translate2(obj, lum);
  punrotate(lum);
  unrotate(lum);
  i.k = (i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.delta >= 0)
    if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
      return (-1);
  return (0);
}

int		inter_cyl_shadow(t_object *obj, t_spobject *lum)
{
  t_inter	i;

  protate(lum, obj);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  translate1(obj, lum);
  rotate(lum, obj);
  i.a = pow(lum->vx, 2) + pow(lum->vy, 2);
  i.b = 2 * (lum->x * lum->vx + lum->y * lum->vy);
  i.c = pow(lum->x, 2) + pow(lum->y, 2) - pow(obj->ray, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (i.b + sqrt(i.delta)) / (2 * i.a);
  translate2(obj, lum);
  punrotate(lum);
  unrotate(lum);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  if (i.delta >= 0)
    if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
      return (-1);
  return (0);
}

int		inter_cone_shadow_delta(t_inter *i)
{
  if (i->delta >= 0)
    if ((i->k2 < 0.9999 && i->k2 > 0.00001)
	|| (i->k < 0.9999 && i->k > 0.00001))
      return (-1);
  return (0);
}

int		inter_cone_shadow(t_object *obj, t_spobject *lum)
{
  t_inter	i;

  protate(lum, obj);
  translate1(obj, lum);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  rotate(lum, obj);
  i.d = 0;
  if (cos(obj->angle) != 0)
    i.d = sin(obj->angle) / cos(obj->angle);
  i.a = pow(lum->vx, 2) + pow(lum->vy, 2) - pow(lum->vz, 2) * pow(i.d, 2);
  i.b = 2 * (lum->x * lum->vx + lum->y * lum->vy -
	     (lum->z * (lum->vz) * pow(i.d, 2)));
  i.c = pow(lum->x, 2) + pow(lum->y, 2) - pow(lum->z, 2) * pow(i.d, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (i.b + sqrt(i.delta)) / (2 * i.a);
  translate2(obj, lum);
  punrotate(lum);
  unrotate(lum);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  return (inter_cone_shadow_delta(&i));
}

int		inter_plan_shadow(t_object *obj, t_spobject *lum)
{
  double	k;

  protate(lum, obj);
  translate1(obj, lum);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  rotate(lum, obj);
  obj->xrot *= -1;
  obj->yrot *= -1;
  obj->zrot *= -1;
  k = lum->z / lum->vz;
  translate2(obj, lum);
  punrotate(lum);
  unrotate(lum);
  if (k < 0.9999 && k > 0.00001)
    return (-1);
  return (0);
}
