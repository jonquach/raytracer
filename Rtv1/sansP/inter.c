/*
** inter.c for inter in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:58 2014 frayss_c
** Last update Tue Jun  3 16:10:39 2014 quach_a
*/

#include <math.h>
#include "rtv1.h"

void		inter_sphere(t_all *all, t_object *sphere)
{
  t_inter	i;

      /* printf("************************************************************************************************************************************************************************************************\n"); */
      /* printf("x %G\n", sphere->x); */
      /* printf("y %G\n", sphere->y); */
      /* printf("z %G\n", sphere->z); */
      /* printf("eyex %G\n", all->eye.x); */
      /* printf("eyey %G\n", all->eye.y); */
      /* printf("eyez %G\n", all->eye.z); */
      /* printf("eyevx %G\n", all->eye.vx); */
      /* printf("eyevy %G\n", all->eye.vy); */
      /* printf("eyevz %G\n", all->eye.vz); */
      /* printf("ray %G\n", sphere->ray); */
      /* printf("xrot %G\n", sphere->xrot); */
      /* printf("yrot %G\n", sphere->yrot); */
      /* printf("zrot %G\n", sphere->zrot); */
      /* printf("type %d\n", sphere->type); */
      /* printf("bright %G\n", sphere->bright); */
      /* printf("color R %d\n", sphere->color[0]); */
      /* printf("color G %d\n", sphere->color[1]); */
      /* printf("color B %d\n", sphere->color[2]); */
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
      calc_lum_vector(all, sphere);
    }
  else if (i.k2 < i.k && i.k2 > 0.00001)
    {
      sphere->k = i.k2;
      my_cos(all, i.k2, 1, sphere);
      translate2(sphere, &all->eye);
      calc_lum_vector(all, sphere);
    }
   else
    translate2(sphere, &all->eye);
  if (i.delta <= 0)
    {
      printf("inside sphere\n");
      sphere->k = -1;
    }
}

void		inter_cyl(t_all *all, t_object *cyl)
{
  t_inter	i;

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
      unrotate(all);
      translate2(cyl, &all->eye);
      calc_lum_vector(all, cyl);
    }
  else if (i.k2 < i.k && i.k2 > 0.00001)
    {
      cyl->k = i.k2;
      my_cos(all, i.k2, 3, cyl);
      unrotate(all);
      translate2(cyl, &all->eye);
      calc_lum_vector(all, cyl);
    }
  else
    {
      unrotate(all);
      translate2(cyl, &all->eye);
    }
  if (i.delta <= 0)
    cyl->k = -1;
}

void		inter_cone2(t_all *all, t_object *cone, t_inter *i)
{
  if (i->k < i->k2 && i->k > 0.00001)
    {
      cone->k = i->k;
      my_cos(all, i->k, 4, cone);
      translate2(cone, &all->eye);
      unrotate(all);
      calc_lum_vector(all, cone);
    }
  else if (i->k2 < i->k && i->k2 > 0.00001)
    {
      cone->k = i->k2;
      my_cos(all, i->k2, 4, cone);
      translate2(cone, &all->eye);
      unrotate(all);
      calc_lum_vector(all, cone);
    }
   else
     {
       unrotate(all);
       translate2(cone, &all->eye);
     }
  if (i->delta <= 0)
    cone->k = -1;
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
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2) - pow(all->eye.vz, 2) * pow(i.d, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y * all->eye.vy
             - (all->eye.z * (all->eye.vz) * pow(i.d, 2)));
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
      calc_lum_vector(all, plan);
    }
   else
     {
       printf("inside plan\n");
       plan->k = -1;
       unrotate(all);
       translate2(plan, &all->eye);
     }
}
