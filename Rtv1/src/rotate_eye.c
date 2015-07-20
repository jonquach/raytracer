/*
** rotate_eye.c for rotate_eye.c in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Jun  8 18:49:42 2014 frayss_c
** Last update Sun Jun  8 21:51:20 2014 quach_a
*/

#include <math.h>
#include "pauvray.h"
#include "rotate.h"

void		rotationeyex(t_spobject *pov, t_spobject *eye)
{
  double	angle1;

  angle1 = (eye->xrot * M_PI) / 180;
  pov->vy = pov->vy * cos(angle1) - pov->vz * sin(angle1);
  pov->vz = pov->vy * sin(angle1) + pov->vz * cos(angle1);
}

void		rotationeyey(t_spobject *pov, t_spobject *eye)
{
  double	angle2;

  angle2 = eye->yrot * M_PI / 180;
  pov->vx = pov->vx * cos(angle2) - pov->vz * sin(angle2);
  pov->vz = pov->vx * sin(angle2) + pov->vz * cos(angle2);
}

void		rotationeyez(t_spobject *pov, t_spobject *eye)
{
  double	angle3;

  angle3 = eye->zrot * M_PI / 180;
  pov->vx = pov->vx * cos(angle3) + pov->vy * sin(angle3);
  pov->vy = -(pov->vx * sin(angle3)) + pov->vy * cos(angle3);
}
