/*
** inter.c for inter in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:58 2014 frayss_c
** Last update Sat Jun  7 14:04:04 2014 han_d
*/

#include <math.h>
#include "rtv1.h"

void		inter_sphere_transpa(t_all *all, t_object *sphere)
{
  t_inter	i;

  translate1(sphere, &all->eye);
  i.a = pow(all->n.px, 2) + pow(all->n.py, 2) + pow(all->n.pz, 2);
  i.b = 2 * (all->n.px * all->transpa.vx + all->n.py
	     * all->transpa.vy + all->n.pz * all->transpa.vz);
  i.c = all->n.px * all->n.px + all->n.py *
    all->n.py + all->n.pz * all->n.pz - sphere->ray * sphere->ray;
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    {
      sphere->k = i.k;
      my_cos(all, i.k, 1, sphere);
      translate2(sphere, &all->eye);
      //cal_lum_vector(all, sphere);
    }
  else if (i.k2 < i.k && i.k2 > 0.00001)
    {
      sphere->k = i.k2;
      my_cos(all, i.k2, 1, sphere);
      translate2(sphere, &all->eye);
      //cal_lum_vector(all, sphere);
    }
  else
    translate2(sphere, &all->eye);
  if (i.delta <= 0)
    sphere->k = -1;
}

void		inter_cyl_transpa(t_all *all, t_object *cyl)
{
  t_inter	i;

  translate1(cyl, &all->eye);
  rotate(all, cyl);
  i.a = pow(all->transpa.vx, 2) + pow(all->transpa.vy, 2);
  i.b = 2 * (all->n.px * all->transpa.vx + all->n.py * all->transpa.vy);
  i.c = pow(all->n.px, 2) + pow(all->n.py, 2) - pow(cyl->ray, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    {
      cyl->k = i.k;
      my_cos(all, i.k, 3, cyl);
      translate2(cyl, &all->eye);
      unrotate(all);
      // calc_lum_vector(all, cyl);
    }
  else if (i.k2 < i.k && i.k2 > 0.00001)
    {
      cyl->k = i.k2;
      my_cos(all, i.k2, 3, cyl);
      unrotate(all);
      translate2(cyl, &all->eye);
      //      calc_lum_vector(all, cyl);
    }
  else
    {
      unrotate(all);
      translate2(cyl, &all->eye);
    }
  if (i.delta <= 0)
    cyl->k = -1;
}

void		inter_cone2_transpa(t_all *all, t_object *cone, t_inter *i)
{
  if (i->k < i->k2 && i->k > 0.00001)
    {
      cone->k = i->k;
      my_cos(all, i->k, 4, cone);
      translate2(cone, &all->eye);
      unrotate(all);
      //cal_lum_vector(all, cone);
    }
  else if (i->k2 < i->k && i->k2 > 0.00001)
    {
      cone->k = i->k2;
      my_cos(all, i->k2, 4, cone);
      translate2(cone, &all->eye);
      unrotate(all);
      //cal_lum_vector(all, cone);
    }
  else
    {
      unrotate(all);
      translate2(cone, &all->eye);
    }
  if (i->delta <= 0)
    cone->k = -1;
}

void		inter_cone_transpa(t_all *all, t_object *cone)
{
  t_inter	i;

  translate1(cone, &all->eye);
  rotate(all, cone);
  if (cos(cone->angle) != 0)
    i.d = sin(cone->angle) / cos(cone->angle);
  else
    i.d = 0;
  i.a = pow(all->transpa.vx, 2) + pow(all->transpa.vy, 2) -
    pow(all->transpa.vz, 2) * pow(i.d, 2);
  i.b = 2 * (all->n.px * all->transpa.vx + all->n.py * all->transpa.vy
             - (all->n.pz * (all->transpa.vz) * pow(i.d, 2)));
  i.c = pow(all->n.px, 2) + pow(all->n.py, 2) - pow(all->n.pz, 2)
    * pow(i.d, 2);
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  inter_cone2(all, cone, &i);
}

void		inter_plan_transpa(t_all *all, t_object *plan)
{
  double	k;

  translate1(plan, &all->eye);
  rotate(all, plan);
  if (all->transpa.vz != 0)
    k = -all->n.pz / all->transpa.vz;
  else
    k = -1;
  if (k > 0.00001)
    {
      plan->k = k;
      my_cos(all, k, 2, plan);
      translate2(plan, &all->eye);
      unrotate(all);
      // cal_lum_vector(all, plan);
    }
  else
    {
      plan->k = -1;
      unrotate(all);
      translate2(plan, &all->eye);
    }
}
