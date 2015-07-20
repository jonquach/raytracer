/*
** plan.c for plan.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/inter
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:43:13 2014 han_d
** Last update Thu Jun  5 17:43:14 2014 han_d
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void            inter_plan(t_all *all, t_object *plan)
{
  double        k;

  translate1(plan, &all->eye);
  rotate(all, plan);
  if (all->eye.vz != 0)
    k = -all->eye.z / all->eye.vz;
  else
    k = -1;
  if (k > 0.00001)
    {
      plan->k = k;
      my_cos(all, k, 2, plan);
      translate2(plan, &all->eye);
      unrotate(all);
      //cal_lum_vector(all, plan);
    }
  else
    {
      plan->k = -1;
      unrotate(all);
      translate2(plan, &all->eye);
    }
}

