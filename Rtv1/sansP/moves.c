/*
** moves.c for moves in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:45 2014 frayss_c
** Last update Fri May 30 15:31:21 2014 frayss_c
*/

#include <math.h>
#include "rtv1.h"

void		rotate(t_all *all, t_object *object)
{
  all->eye.x2 = all->eye.vx;
  all->eye.y2 = all->eye.vy;
  all->eye.z2 = all->eye.vz;
  rotationx(all, object);
  rotationy(all, object);
  rotationz(all, object);
}

void		unrotate(t_all *all)
{
  all->eye.vx = all->eye.x2;
  all->eye.vy = all->eye.y2;
  all->eye.vz = all->eye.z2;
}

void		rotatel(t_all *all, t_object *object)
{
  all->lum.x2 = all->lum.vx;
  all->lum.y2 = all->lum.vy;
  all->lum.z2 = all->lum.vz;
  rotationxl(all, object);
  rotationyl(all, object);
  rotationzl(all, object);
}

void		unrotatel(t_all *all)
{
  all->lum.vx = all->lum.x2;
  all->lum.vy = all->lum.y2;
  all->lum.vz = all->lum.z2;
}

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
