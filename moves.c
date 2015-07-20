/*
** moves.c for moves in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:45 2014 frayss_c
** Last update Fri May 23 17:06:30 2014 frayss_c
*/

#include <math.h>
#include "rtv1.h"

void		rotate(t_all *all, t_object *object)
{
  all->v.x2 = all->v.x;
  all->v.y2 = all->v.y;
  all->v.z2 = all->v.z;
  rotationx(all, object);
  rotationy(all, object);
  rotationz(all, object);
}

void		unrotate(t_all *all)
{
  all->v.x = all->v.x2;
  all->v.y = all->v.y2;
  all->v.z = all->v.z2;
}

void		rotationx(t_all *all, t_object *object)
{
  double	angle1;

  angle1 = (object->xrot * M_PI) / 180;
  all->v.y = all->v.y * cos(angle1) + all->v.z * sin(angle1);
  all->v.z = -(all->v.y * sin(angle1)) + all->v.z * cos(angle1);
}

void		rotationy(t_all *all, t_object *object)
{
  double	angle2;

  angle2 = object->yrot * M_PI / 180;
  /* all->v.x = all->v.x * sin(angle2) + all->v.z * cos(angle2); */
  /* all->v.z = all->v.x * cos(angle2) - all->v.z * sin(angle2); */
  all->v.x = all->v.x * cos(angle2) - all->v.z * sin(angle2);
  all->v.z = all->v.x * sin(angle2) + all->v.z * cos(angle2);
}

void		rotationz(t_all *all, t_object *object)
{
  double	angle3;

  angle3 = object->zrot * M_PI / 180;
  /* all->v.x = all->v.x * cos(angle3) - all->v.y * sin(angle3); */
  /* all->v.y = all->v.x * sin(angle3) + all->v.y * cos(angle3); */
  all->v.x = all->v.x * cos(angle3) + all->v.y * sin(angle3);
  all->v.y = -(all->v.x * sin(angle3)) + all->v.y * cos(angle3);
}
