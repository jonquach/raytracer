/*
** sphere.c for sphere.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/inter
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:43:20 2014 han_d
** Last update Sat Jun  7 16:44:40 2014 
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void            inter_sphere(t_all *all, t_object *sphere)
{
  t_inter       i;

  translate1(sphere, &all->eye);
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2) + pow(all->eye.vz, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y
             * all->eye.vy + all->eye.z * all->eye.vz);
  i.c = all->eye.x * all->eye.x + all->eye.y *
    all->eye.y + all->eye.z * all->eye.z - sphere->ray * sphere->ray;
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
