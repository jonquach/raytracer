/*
** cone.c for cone.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/inter
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:41:21 2014 han_d
** Last update Sun Jun  8 17:17:45 2014 
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void            inter_cone2(t_all *all, t_object *cone, t_inter *i, int index)
{
  if (i->k < i->k2 && i->k > 0.00001)
    find_tmp_color(all, obj, index, i->k);
  else if (i->k2 < i->k && i->k2 > 0.00001)
    find_tmp_color(all, obj, index, i->K2);
  punrotate(&all->eye);
  unrotate(&all->eye);
  translate2(obj, &all->eye);
  if (i->delta <= 0)
    obj->k = -1;
  calc_color(obj, all);
}

void            inter_cone(t_all *all, t_object *cone)
{
  t_inter       i;

  translate1(cone, &all->eye);
  rotate(all, cone);
  if (cos(cone->angle) != 0)
    i.d = sin(cone->angle) / cos(cone->angle);
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
  inter_cone2(all, cone, &i);
}
