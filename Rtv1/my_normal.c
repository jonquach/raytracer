/*
** light.c for light in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:33 2014 frayss_c
** Last update Sat Jun  7 14:55:19 2014 han_d
*/

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

void	my_normal_2(t_all *all, t_object *obj)
{
  if (obj->type == 3)
    {
      all->n.nx = all->n.px;
      all->n.ny = all->n.py;
      all->n.nz = 0;
    }
  else if (obj->type == 4)
    {
      all->n.nx = all->n.px + 0;
      all->n.ny = all->n.py + 0;
      all->n.nz = 0;
    }
}

void	my_normal(t_all *all, t_object *obj)
{
  if (obj->type == 1)
    {
      all->n.nx = all->n.px;
      all->n.ny = all->n.py;
      all->n.nz = all->n.pz;
    }
  else if (obj->type == 2)
    {
      all->n.nx = 0;
      // cos(all->n.px / 10) *
      // (sqrt(pow(all->n.nx, 2) + pow(all->n.py,2) + pow(all->n.nz, 2)) / 10);
      all->n.ny = 0;
      // cos(all->n.py / 10) *
      // (sqrt(pow(all->n.nx, 2) + pow(all->n.py,2) + pow(all->n.nz, 2)) / 10);
      if (obj->z < all->eye.z)
	all->n.nz = 100;
      else
	all->n.nz = -100;
    }
  my_normal_2(all, obj);
}
