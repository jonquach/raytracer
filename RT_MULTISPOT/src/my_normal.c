/*
** my_normal.c for my_normal.c in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat Jun  7 23:33:07 2014 quach_a
** Last update Sun Jun  8 23:20:26 2014 
*/

#include <math.h>
#include "pauvray.h"

void	my_trouble(t_all *all, t_object *obj)
{
  if (obj->trouble == 1)
    all->norm.normx += cos(all->norm.pointx / 10) *
      (sqrt(pow(all->norm.normx, 2) + pow(all->norm.normy, 2)
	    + pow(all->norm.normz, 2)) / 10);
}
void	my_normal_2(t_all *all, t_object *obj)
{
  if (obj->type == 4)
    {
      all->norm.normx = all->norm.pointx;
      all->norm.normy = all->norm.pointy;
      all->norm.normz = 0;
    }
}

void	my_normal(t_all *all, t_object *obj)
{
  if (obj->type == 1)
    {
      all->norm.normx = all->norm.pointx;
      all->norm.normy = all->norm.pointy;
      all->norm.normz = all->norm.pointz;
    }
  else if (obj->type == 2)
    {
      all->norm.normx = 0;
      all->norm.normy = 0;
      all->norm.normz = 100;
      if (all->eye.z < 0)
	all->norm.normz *= -1;
    }
  else if (obj->type == 3)
    {
      all->norm.normx = all->norm.pointx;
      all->norm.normy = all->norm.pointy;
      all->norm.normz = 0;
    }
  else
    my_normal_2(all, obj);
  my_trouble(all, obj);
}
