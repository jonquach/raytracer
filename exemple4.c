/*
** set.c for set in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:11 2014 frayss_c
** Last update Sat May 24 19:40:34 2014 frayss_c
*/

#include <math.h>
#include "rtv1.h"

void	set_sphere(t_all *all)
{
  all->sphere.x = 400;
  all->sphere.y = 0;
  all->sphere.z = 10000;
  all->sphere.ray = 170;
  all->sphere.xrot = 0;
  all->sphere.yrot = 0;
  all->sphere.zrot = 0;
}

void	set_plan(t_all *all)
{
  all->plan.x = 0;
  all->plan.y = 0;
  all->plan.z = -100;
  all->plan.xrot = 0;
  all->plan.yrot = 0;
  all->plan.zrot = 0;
}

void	set_cone(t_all *all)
{
  all->cone.x = 400;
  all->cone.y = 0;
  all->cone.z = 100;
  all->cone.xrot = 330;
  all->cone.yrot = 0;
  all->cone.zrot = 0;
  all->cone.angle = 20 * M_PI / 180;
}

void	set_cyl(t_all *all)
{
  all->cyl.x = 400;
  all->cyl.y = 20000;
  all->cyl.z = -10000;
  all->cyl.ray = 70;
  all->cyl.xrot = 0;
  all->cyl.yrot = 0;
  all->cyl.zrot = 0;
}

void	set_value(t_all *all)
{
  all->my.k_color = 0;
  all->color[0][0] = 0;
  all->color[0][1] = 0;
  all->color[0][2] = 0;
  all->my.x_size = 1000;
  all->my.y_size = 1000;
  all->eye.x = -300;
  all->eye.y = 0;
  all->eye.z = 50;
  all->lum.x = -1000;
  all->lum.y = 200;
  all->lum.z = 1000;
  set_sphere(all);
  set_plan(all);
  set_cyl(all);
  set_cone(all);
}
