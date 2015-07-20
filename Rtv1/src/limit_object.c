/*
** limit_object.c for limit_object.c in /home/rechou_f/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by fabien rechou
** Login   <rechou_f@epitech.net>
** 
** Started on  Sat Jun  7 19:20:11 2014 fabien rechou
** Last update Sun Jun  8 21:54:54 2014 kauch_j
*/

#include "pauvray.h"
#include "math.h"

double		limit_cone_up(t_all *all, t_object *cone)
{
  if (cone->z < all->eye.z + cone->k * all->eye.vz)
    cone->zbis = 0;
  else
    {
      cone->zbis = pow((all->eye.x - cone->x) + (cone->k * all->eye.vx), 2)
	+ pow((all->eye.y - cone->y) + (cone->k * all->eye.vy), 2)
	+ pow((all->eye.z - cone->z) + (cone->k * all->eye.vz), 2);
      cone->zbis = sqrt(cone->zbis);
    }
  if (cone->zbis <= 0 || cone->zbis >= cone->limit2)
    cone->k = -1;
  return (cone->k);
}

double		limit_cone_down(t_all *all, t_object *cone)
{
  if (cone->z > all->eye.z + cone->k * all->eye.vz)
    cone->zbis = 0;
  else
    {
      cone->zbis = pow((all->eye.x - cone->x) + (cone->k * all->eye.vx), 2)
	+ pow((all->eye.y - cone->y) + (cone->k * all->eye.vy), 2)
	+ pow((all->eye.z - cone->z) + (cone->k * all->eye.vz), 2);
      cone->zbis = sqrt(cone->zbis);
    }
  if (cone->zbis < 0)
    cone->zbis = -cone->zbis;
  if (cone->zbis <= 0 || cone->zbis >= cone->limit1)
    cone->k = -1;
  return (cone->k);
}

double		limit_cone_double(t_all *all, t_object *cone)
{
  cone->zbis = pow((all->eye.x - cone->x) + (cone->k * all->eye.vx), 2)
    + pow((all->eye.y - cone->y) + (cone->k * all->eye.vy), 2)
    + pow((all->eye.z - cone->z) + (cone->k * all->eye.vz), 2);
  cone->zbis = sqrt(cone->zbis);
  if (cone->zbis < 0)
    cone->zbis = -cone->zbis;
  if (cone->zbis >= cone->limit1 || cone->zbis >= cone->limit2)
    cone->k = -1;
  return (cone->k);
}
