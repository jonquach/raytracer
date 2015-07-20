/*
** transparency.c for transparency in /home/rechou_f/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by fabien rechou
** Login   <rechou_f@epitech.net>
** 
** Started on  Sat May 31 16:54:34 2014 fabien rechou
** Last update Thu Jun  5 17:51:42 2014 han_d
*/

#include <math.h>
#include "../rtv1.h"
#include "../prototype.h"

double		first_angle(t_all *all, int bool)
{
  double	angle;

  if (bool == 0)
    {
      angle = all->eye.vx * all->n.nx + all->eye.vy * all->n.ny
	+ all->eye.vz * all->n.nz;
    }
  else
    {
      angle = all->transpa.vx * -all->n.nx + all->transpa.vy * -all->n.ny
	+ all->transpa.vz * -all->n.nz;
    }
  return (angle);
}

t_all		*first_refract(t_all *all)
{
  double	angle1;
  double	angle2;
  double	value;

  angle1 = first_angle(all, 0);
  angle2 = angle1 * 2 / 3;
  value = sin(angle2) / sin(angle1);
  all->transpa.vx = value * all->eye.vx - cos(angle2)
    + value * (all->eye.vx * all->n.nx) * all->n.nx;
  all->transpa.vy = value * all->eye.vy - cos(angle2)
    + value * (all->eye.vy * all->n.ny) * all->n.ny;
  all->transpa.vz = value * all->eye.vz - cos(angle2)
    + value * (all->eye.vz * all->n.nx) * all->n.nz;
  return (all);
}

t_all		*second_refract(t_all *all)
{
  double	angle1;
  double	angle2;
  double	value;

  angle1 = first_angle(all, 1);
  angle2 = angle1 * 3 / 2;
  value = sin(angle2) / sin(angle1);
  all->transpa.vx = value * all->transpa.vx - cos(angle2)
    + value * (all->transpa.vx * all->n.nx) * all->n.nx;
  all->transpa.vy = value * all->transpa.vy - cos(angle2)
    + value * (all->transpa.vy * all->n.ny) * all->n.ny;
  all->transpa.vz = value * all->transpa.vz - cos(angle2)
    + value * (all->transpa.vz * all->n.nx) * all->n.nz;
  return (all);
}

t_all		*get_vect_transp(t_all *all)
{

  if (all->objects[all->my.k_color].transparency == 0)
    {
      all = first_refraction(all);
      all = second_refraction(all);
    }
}
