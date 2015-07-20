/*
** inter_cone.c for inter_cone.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:34:13 2014 han_d
** Last update Sun Jun  8 21:52:33 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"
#include "inter.h"
#include "rotate.h"

void		inter_cone2(t_all *all, t_object *obj, t_inter *i, int index)
{
  obj->up = 5;
  obj->limit1 = 3000;
  obj->limit2 = 3000;
  if (i->k < i->k2 && i->k > 0.00001)
    find_tmp_color(all, obj, index, i->k);
  else if (i->k2 < i->k && i->k2 > 0.00001)
    find_tmp_color(all, obj, index, i->k2);
  punrotate(&all->eye);
  unrotate(&all->eye);
  translate2(obj, &all->eye);
  if (obj->up == 0)
    limit_cone_up(all, obj);
  else if (obj->up == 1)
    limit_cone_down(all, obj);
  else
    limit_cone_double(all, obj);
  if (i->delta <= 0)
    obj->k = -1;
  calc_color(obj, all);
}

void		inter_cone(t_all *all, t_object *obj, int index)
{
  t_inter	i;

  obj->xrot *= -1;
  translate1(obj, &all->eye);
  protate(&all->eye, obj);
  rotate(&all->eye, obj);
  if (cos(obj->angle) != 0)
    i.d = sin(obj->angle) / cos(obj->angle);
  else
    i.d = 0;
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2) - pow(all->eye.vz, 2) *
    pow(i.d, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y * all->eye.vy
             - (all->eye.z * (all->eye.vz) * pow(i.d, 2)));
  i.c = pow(all->eye.x, 2) + pow(all->eye.y, 2) - pow(all->eye.z, 2)
    * pow(i.d, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  inter_cone2(all, obj, &i, index);
  obj->xrot *= -1;
}
