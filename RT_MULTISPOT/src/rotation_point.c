/*
** rotation_point.c for rotate in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/src
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sun Jun  8 21:48:57 2014 quach_a
** Last update Sun Jun  8 21:49:08 2014 quach_a
*/

#include <math.h>
#include "pauvray.h"
#include "rotate.h"

void		rotationx(t_spobject *pov, t_object *object)
{
  double	angle1;

  angle1 = (object->xrot * M_PI) / 180;
  pov->vy = pov->vy * cos(angle1) - pov->vz * sin(angle1);
  pov->vz = pov->vy * sin(angle1) + pov->vz * cos(angle1);
}

void		rotationy(t_spobject *pov, t_object *object)
{
  double	angle2;

  angle2 = object->yrot * M_PI / 180;
  pov->vx = pov->vx * cos(angle2) - pov->vz * sin(angle2);
  pov->vz = pov->vx * sin(angle2) + pov->vz * cos(angle2);
}

void		rotationz(t_spobject *pov, t_object *object)
{
  double	angle3;

  angle3 = object->zrot * M_PI / 180;
  pov->vx = pov->vx * cos(angle3) + pov->vy * sin(angle3);
  pov->vy = -(pov->vx * sin(angle3)) + pov->vy * cos(angle3);
}

