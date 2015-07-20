/*
** set.c for set in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:11 2014 frayss_c
** Last update Mon May 26 16:48:30 2014 frayss_c
*/

#include <math.h>
#include "rtv1.h"

void	set_sphere(t_all *all, int i)
{
  all->objects[i].x = -200;
  all->objects[i].y = 0;
  all->objects[i].z = 500;
  all->objects[i].ray = 170;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = SPHERE;
  all->objects[i].bright = 0.7;
}

void	set_sphere1(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -200;
  all->objects[i].z = 1000;
  all->objects[i].ray = 170;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = SPHERE;
  all->objects[i].bright = 0;
}

void	set_plan(t_all *all, int i)
{
  all->objects[i].x = 0;
  all->objects[i].y = 0;
  all->objects[i].z = 0;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = PLAN;
  all->objects[i].bright = 0.2;
}

void	set_cone(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -150;
  all->objects[i].z = 0;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].angle = 40 * M_PI / 180;
  all->objects[i].type = CONE;
  all->objects[i].bright = 0.2;
}

void	set_cyl(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = 200;
  all->objects[i].z = 0;
  all->objects[i].ray = 70;
  all->objects[i].xrot = 45;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = CYLINDER;
  all->objects[i].bright = 0.1;
}

void	set_value(t_all *all)
{
  all->my.k_color = 0;
  all->color[0][0] = 0;
  all->color[0][1] = 0;
  all->color[0][2] = 0;
  all->my.x_size = 1000;
  all->my.y_size = 1000;
  all->eye.x = -3000;
  all->eye.y = 0;
  all->eye.z = 500;
  all->lum.x = -1000;
  all->lum.y = 200;
  all->lum.z = 1000;
  all->lum.color[0] = 0;
  all->lum.color[1] = 0;
  all->lum.color[2] = 255;
  set_sphere(all, 0);
  set_sphere1(all, 4);
  set_plan(all, 1);
  set_cyl(all, 3);
  set_cone(all, 2);
}
