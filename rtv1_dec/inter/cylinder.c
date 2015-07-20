/*
** cylinder.c for cylinder.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/inter
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:42:34 2014 han_d
** Last update Thu Jun  5 17:42:36 2014 han_d
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void            inter_cyl(t_all *all, t_object *cyl)
{
  t_inter       i;

  translate1(cyl, &all->eye);
  rotate(all, cyl);
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y * all->eye.vy);
  i.c = pow(all->eye.x, 2) + pow(all->eye.y, 2) - pow(cyl->ray, 2);
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
      // calc_lum_vector(all, cyl);
    }
  else
    {
      unrotate(all);
      translate2(cyl, &all->eye);
    }
  if (i.delta <= 0)
    cyl->k = -1;
}
