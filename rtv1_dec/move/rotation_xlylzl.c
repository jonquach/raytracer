/*
** rotation_xlylzl.c for rotation_xlylzl.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/move
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:59:08 2014 han_d
** Last update Thu Jun  5 18:01:05 2014 han_d
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void		rotationxl(t_all *all, t_object *object)
{
  double	angle1;

  angle1 = (object->xrot * M_PI) / 180;
  all->lum.vy = all->lum.vy * cos(angle1) + all->lum.vz * sin(angle1);
  all->lum.vz = -(all->lum.vy * sin(angle1)) + all->lum.vz * cos(angle1);
}

void		rotationyl(t_all *all, t_object *object)
{
  double	angle2;

  angle2 = object->yrot * M_PI / 180;
  /* all->lum.vx = all->lum.vx * sin(angle2) + all->lum.vz * cos(angle2); */
  /* all->lum.vz = all->lum.vx * cos(angle2) - all->lum.vz * sin(angle2); */
  all->lum.vx = all->lum.vx * cos(angle2) - all->lum.vz * sin(angle2);
  all->lum.vz = all->lum.vx * sin(angle2) + all->lum.vz * cos(angle2);
}

void		rotationzl(t_all *all, t_object *object)
{
  double	angle3;

  angle3 = object->zrot * M_PI / 180;
  /* all->lum.vx = all->lum.vx * cos(angle3) - all->lum.vy * sin(angle3); */
  /* all->lum.vy = all->lum.vx * sin(angle3) + all->lum.vy * cos(angle3); */
  all->lum.vx = all->lum.vx * cos(angle3) + all->lum.vy * sin(angle3);
  all->lum.vy = -(all->lum.vx * sin(angle3)) + all->lum.vy * cos(angle3);
}
