/*
** rotation_xyz.c for rotation_xyz.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/move
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 17:56:04 2014 han_d
** Last update Sat Jun  7 13:34:38 2014 han_d
*/

#include <math.h>
#include "rtv1.h"

void		rotationx(t_all *all, t_object *object)
{
  double	angle1;

  angle1 = (object->xrot * M_PI) / 180;
  all->eye.vy = all->eye.vy * cos(angle1) + all->eye.vz * sin(angle1);
  all->eye.vz = -(all->eye.vy * sin(angle1)) + all->eye.vz * cos(angle1);
}

void		rotationy(t_all *all, t_object *object)
{
  double	angle2;

  angle2 = object->yrot * M_PI / 180;
  /* all->eye.vx = all->eye.vx * sin(angle2) + all->eye.vz * cos(angle2); */
  /* all->eye.vz = all->eye.vx * cos(angle2) - all->eye.vz * sin(angle2); */
  all->eye.vx = all->eye.vx * cos(angle2) - all->eye.vz * sin(angle2);
  all->eye.vz = all->eye.vx * sin(angle2) + all->eye.vz * cos(angle2);
}

void		rotationz(t_all *all, t_object *object)
{
  double	angle3;

  angle3 = object->zrot * M_PI / 180;
  /* all->eye.vx = all->eye.vx * cos(angle3) - all->eye.vy * sin(angle3); */
  /* all->eye.vy = all->eye.vx * sin(angle3) + all->eye.vy * cos(angle3); */
  all->eye.vx = all->eye.vx * cos(angle3) + all->eye.vy * sin(angle3);
  all->eye.vy = -(all->eye.vx * sin(angle3)) + all->eye.vy * cos(angle3);
}
