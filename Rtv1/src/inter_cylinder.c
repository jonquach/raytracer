/*
** inter_cylinder.c for inter_cylinder.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:34:34 2014 han_d
** Last update Sun Jun  8 21:53:04 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"
#include "inter.h"
#include "rotate.h"

void		inter_cyl(t_all *all, t_object *obj, int index)
{
  t_inter	i;

  translate1(obj, &all->eye);
  protate(&all->eye, obj);
  rotate(&all->eye, obj);
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y * all->eye.vy);
  i.c = pow(all->eye.x, 2) + pow(all->eye.y, 2) - pow(obj->ray, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    find_tmp_color(all, obj, index, i.k);
  else if (i.k2 < i.k && i.k2 > 0.00001)
    find_tmp_color(all, obj, index, i.k2);
  punrotate(&all->eye);
  unrotate(&all->eye);
  translate2(obj, &all->eye);
  if (i.delta <= 0)
    obj->k = -1;
  calc_color(obj, all);
}
