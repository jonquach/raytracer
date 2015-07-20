/*
** inter.c for inter in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:58 2014 frayss_c
** Last update Mon May 26 14:16:26 2014 frayss_c
*/

#include <math.h>
#include "rtv1.h"

void		inter_sphere(t_all *all, t_object *sphere)
{
  t_inter	i;

  translate1(sphere, &all->eye);
  i.a = pow(all->v.x, 2) + pow(all->v.y, 2) + pow(all->v.z, 2);
  i.b = 2 * (all->eye.x * all->v.x + all->eye.y
	     * all->v.y + all->eye.z * all->v.z);
  i.c = all->eye.x * all->eye.x + all->eye.y *
    all->eye.y + all->eye.z * all->eye.z - sphere->ray * sphere->ray;
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    {
      sphere->k = i.k;
      my_cos(all, i.k, 1, sphere);
    }
  else
    {
      sphere->k = i.k2;
      my_cos(all, i.k2, 1, sphere);
    }
  if (i.delta <= 0)
    sphere->k = -1;
  all->my.count++;
  translate2(sphere, &all->eye);
}

void		inter_cyl(t_all *all, t_object *cyl)
{
  t_inter	i;

  translate1(cyl, &all->eye);
  rotate(all, cyl);
    i.a = pow(all->v.x, 2) + pow(all->v.y, 2);
  i.b = 2 * (all->eye.x * all->v.x + all->eye.y * all->v.y);
  i.c = pow(all->eye.x, 2) + pow(all->eye.y, 2) - pow(cyl->ray, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    {
      cyl->k = i.k;
      my_cos(all, i.k, 3, cyl);
    }
  else
    {
      cyl->k = i.k2;
      my_cos(all, i.k2, 3, cyl);
    } 
  unrotate(all);
  translate2(cyl, &all->eye);
  if (i.delta <= 0)
    cyl->k = -1;
  all->my.count++;
}

void		inter_cone2(t_all *all, t_object *cone, t_inter *i)
{
  if (i->k < i->k2 && i->k > 0.00001)
    {
      cone->k = i->k;
      my_cos(all, i->k, 4, cone);
    }
  else
    {
      cone->k = i->k2;
      my_cos(all, i->k2, 4, cone);
    }
  unrotate(all);
  translate2(cone, &all->eye);
  if (i->delta <= 0)
    cone->k = -1;
  all->my.count++;
}

void		inter_cone(t_all *all, t_object *cone)
{
  t_inter	i;

  translate1(cone, &all->eye);
  rotate(all, cone);
  if (cos(cone->angle) != 0)
    i.d = sin(cone->angle) / cos(cone->angle);
  else
    i.d = 0;
  i.a = pow(all->v.x, 2) + pow(all->v.y, 2) - pow(all->v.z, 2) * pow(i.d, 2);
  i.b = 2 * (all->eye.x * all->v.x + all->eye.y * all->v.y
             - (all->eye.z * (all->v.z) * pow(i.d, 2)));
  i.c = pow(all->eye.x, 2) + pow(all->eye.y, 2) - pow(all->eye.z, 2)
    * pow(i.d, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  inter_cone2(all, cone, &i);
}

void		inter_plan(t_all *all, t_object *plan)
{
  double	k;

  translate1(plan, &all->eye);
  rotate(all, plan);
  if (all->v.z != 0)
    k = -all->eye.z / all->v.z;
  else
    k = -1;
  if (k > 0.00001)
    {
      plan->k = k;
      my_cos(all, k, 2, plan);
    }
  else
    plan->k = -1;
  unrotate(all);
  translate2(plan, &all->eye);
  all->my.count++;
}