/*
** set_objects.c for set_objects.c in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:11 2014 frayss_c
** Last update Sat Jun  7 13:27:49 2014 han_d
*/

#include <math.h>
#include "rt.h"
#include "rtv1.h"

void	set_sphere(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -400;
  all->objects[i].z = 170;
  all->objects[i].ray = 170;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = SPHERE;
  all->objects[i].bright = 0;
}

void	set_plan(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = 0;
  all->objects[i].z = -100;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = PLAN;
  all->objects[i].bright = 0.2;
}

void	set_cone(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -200;
  all->objects[i].z = 100;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].angle = 10 * M_PI / 180;
  all->objects[i].type = CONE;
  all->objects[i].bright = 0.7;
}

void	set_cyl(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = 200;
  all->objects[i].z = 0;
  all->objects[i].ray = 70;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = CYLINDER;
  all->objects[i].bright = 0.2;
}
