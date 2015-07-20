/*
** rotate_unrotate.c for rotate_unrotate.c in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Sat Jun  7 23:02:46 2014 kauch_j
** Last update Sun Jun  8 21:50:59 2014 quach_a
*/

#include "pauvray.h"
#include "rotate.h"

void	protate(t_spobject *pov, t_object *object)
{
  pov->tmpx = pov->x;
  pov->tmpy = pov->y;
  pov->tmpz = pov->z;
  protationx(pov, object);
  protationy(pov, object);
  protationz(pov, object);
}

void	punrotate(t_spobject *pov)
{
  pov->x = pov->tmpx;
  pov->y = pov->tmpy;
  pov->z = pov->tmpz;
}

void	rotate(t_spobject *pov, t_object *object)
{
  pov->x2 = pov->vx;
  pov->y2 = pov->vy;
  pov->z2 = pov->vz;
  rotationx(pov, object);
  rotationy(pov, object);
  rotationz(pov, object);
}

void	unrotate(t_spobject *pov)
{
  pov->vx = pov->x2;
  pov->vy = pov->y2;
  pov->vz = pov->z2;
}

void	rotate_eye(t_spobject *pov, t_spobject *eye)
{
  pov->x2 = pov->vx;
  pov->y2 = pov->vy;
  pov->z2 = pov->vz;
  rotationeyex(pov, eye);
  rotationeyey(pov, eye);
  rotationeyez(pov, eye);
}
