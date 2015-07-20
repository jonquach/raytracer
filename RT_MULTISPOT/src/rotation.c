/*
** rotation_xyz.c for rotation_xyz.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 23:03:42 2014 han_d
** Last update Sun Jun  8 21:49:40 2014 quach_a
*/

#include <math.h>
#include "pauvray.h"
#include "rotate.h"

void		protationx(t_spobject *pov, t_object *object)
{
  double	angle1;

  angle1 = (object->xrot * M_PI) / 180;
  pov->y = pov->y * cos(angle1) + pov->z * sin(angle1);
  pov->z = -(pov->y * sin(angle1)) + pov->z * cos(angle1);
}

void		protationy(t_spobject *pov, t_object *object)
{
  double	angle2;

  angle2 = object->yrot * M_PI / 180;
  pov->x = pov->x * cos(angle2) - pov->z * sin(angle2);
  pov->z = pov->x * sin(angle2) + pov->z * cos(angle2);
}

void		protationz(t_spobject *pov, t_object *object)
{
  double	angle3;

  angle3 = object->zrot * M_PI / 180;
  pov->x = pov->x * cos(angle3) + pov->y * sin(angle3);
  pov->y = -(pov->x * sin(angle3)) + pov->y * cos(angle3);
}
