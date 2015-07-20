/*
** inter.c for inter in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:58 2014 frayss_c
** Last update Sun Jun  8 18:35:49 2014 fabien rechou
*/

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

int		inter_sphere_shadow(t_all *all, t_object *sphere)
{
  t_inter	i;

  translate1(sphere, &all->lum);
  i.a = pow(all->lum.vx, 2) + pow(all->lum.vy, 2) + pow(all->lum.vz, 2);
  i.b = 2 * (all->lum.x * all->lum.vx + all->lum.y
	     * all->lum.vy + all->lum.z * all->lum.vz);
  i.c = all->lum.x * all->lum.x + all->lum.y *
    all->lum.y + all->lum.z * all->lum.z - sphere->ray * sphere->ray;
  i.delta = i.b * i.b - 4 * i.a * i.c;
  translate2(sphere, &all->lum);
  if (i.delta >= 0)
    {
      i.k = -(-i.b - sqrt(i.delta)) / (2 * i.a);
      i.k2 = -(-i.b + sqrt(i.delta)) / (2 * i.a);
      if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
	return (-1);
    }
  return (0);
}

int		inter_cyl_shadow(t_all *all, t_object *cyl)
{
  t_inter	i;

  translate1(cyl, &all->lum);
  rotatel(all, cyl);
  i.a = pow(all->lum.vx, 2) + pow(all->lum.vy, 2);
  i.b = 2 * (all->lum.x * all->lum.vx + all->lum.y * all->lum.vy);
  i.c = pow(all->lum.x, 2) + pow(all->lum.y, 2) - pow(cyl->ray, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = -(-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = -(-i.b + sqrt(i.delta)) / (2 * i.a);
  unrotatel(all);
  translate2(cyl, &all->lum);
  if (i.delta >= 0)
    {
      if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
	return (-1);
    }
  return (0);
}

int		inter_cone_shadow(t_all *all, t_object *cone)
{
  t_inter	i;

  translate1(cone, &all->lum);
  rotatel(all, cone);
  if (cos(cone->angle) != 0)
    i.d = sin(cone->angle) / cos(cone->angle);
  else
    i.d = 0;
  i.a = pow(all->lum.vx, 2) + pow(all->lum.vy, 2) - pow(all->lum.vz, 2) *
    pow(i.d, 2);
  i.b = 2 * (all->lum.x * all->lum.vx + all->lum.y * all->lum.vy
	     - (all->lum.z * (all->lum.vz) * pow(i.d, 2)));
  i.c = pow(all->lum.x, 2) + pow(all->lum.y, 2) - pow(all->lum.z, 2)
    * pow(i.d, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = -(-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = -(-i.b + sqrt(i.delta)) / (2 * i.a);
  translate2(cone, &all->lum);
  unrotatel(all);
  if (cone->up == 0)
    i = limit_shadow_cone_up(all, cone, &i);
  else if (cone->up == 1)
    i = limit_shadow_cone_down(all, cone, &i);
  else
    i = limit_shadow_cone_double(all, cone, &i); 
  if (i.delta >= 0)
    if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
      {
	if ((i.k2 < 0.9999 && i.k2 > 0.00001) || (i.k < 0.9999 && i.k > 0.00001))
	  return (-1);
      }
  return (0);
}

int		inter_plan_shadow(t_all *all, t_object *plan)
{
  double	k;

  translate1(plan, &all->lum);
  rotatel(all, plan);
  k = all->lum.z / all->lum.vz;
  translate2(plan, &all->lum);
  unrotatel(all);
  if (k < 0.9999 && k > 0.00001)
    return (-1);
  return (0);
}
