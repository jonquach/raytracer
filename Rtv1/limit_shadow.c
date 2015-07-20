/*
** limit_object.c for limit_object.c in /home/rechou_f/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by fabien rechou
** Login   <rechou_f@epitech.net>
** 
** Started on  Sat Jun  7 19:20:11 2014 fabien rechou
** Last update Sun Jun  8 18:39:10 2014 fabien rechou
*/

#include "rtv1.h"
#include "math.h"

t_inter		limit_shadow_cone_up(t_all *all, t_object *cone, t_inter *i)
{  
  //  printf("%f, %f, %f, %f\n", cone->z, all->lum.z , i->k, all->lum.vz);
  if (cone->z < all->lum.z - all->lum.vz)
    i->k = -1;
  if (cone->z < all->lum.z -  all->lum.vz)
    i->k2 = -1;
  /*  else
    {
      cone->zbis = pow(all->lum.x + (i->k * all->lum.vx), 2)
	+ pow(all->lum.y + (i->k * all->lum.vy), 2)
	+ pow(all->lum.z + (i->k * all->lum.vz), 2);
      cone->zbis = sqrt(cone->zbis);
    }
  if (cone->zbis <= 0 || cone->zbis >= cone->limit2)
  i->k = -1;*/
  return (*i);
}

t_inter	limit_shadow_cone_down(t_all *all, t_object *cone, t_inter *i)
{
  if (cone->z > all->eye.tmpz + i->k * all->lum.vz)
    cone->zbis = -1;
  else
    {
      cone->zbis = pow(all->lum.x + (i->k * all->lum.vx), 2)
	+ pow(all->lum.y + (i->k * all->lum.vy), 2)
	+ pow(all->lum.z + (i->k * all->lum.vz), 2);
      cone->zbis = sqrt(cone->zbis);
    }
  if (cone->zbis < 0)
    cone->zbis = -cone->zbis;
  if (cone->zbis <= 0 || cone->zbis >= cone->limit1)
    i->k = -1;
  return (*i);
}

t_inter	limit_shadow_cone_double(t_all *all, t_object *cone, t_inter *i)
{
  cone->zbis = pow(all->lum.x + (i->k * all->lum.vx), 2)
    + pow(all->lum.y + (i->k * all->lum.vy), 2)
    + pow(all->lum.z + (i->k * all->lum.vz), 2);
  cone->zbis = sqrt(cone->zbis);
  if (cone->zbis < 0)
    cone->zbis = -cone->zbis;
  if (cone->zbis >= cone->limit1 || cone->zbis >= cone->limit2)
    i->k = -1;
  return (*i);
}
