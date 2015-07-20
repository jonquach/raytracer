/*
** rotate_unrotate.c for rotate_unrotate.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec/move
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 18:04:22 2014 han_d
** Last update Thu Jun  5 18:04:23 2014 han_d
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void	rotate(t_all *all, t_object *object)
{
  all->eye.x2 = all->eye.vx;
  all->eye.y2 = all->eye.vy;
  all->eye.z2 = all->eye.vz;
  rotationx(all, object);
  rotationy(all, object);
  rotationz(all, object);
}

void	unrotate(t_all *all)
{
  all->eye.vx = all->eye.x2;
  all->eye.vy = all->eye.y2;
  all->eye.vz = all->eye.z2;
}

void	rotatel(t_all *all, t_object *object)
{
  all->lum.x2 = all->lum.vx;
  all->lum.y2 = all->lum.vy;
  all->lum.z2 = all->lum.vz;
  rotationxl(all, object);
  rotationyl(all, object);
  rotationzl(all, object);
}

void	unrotatel(t_all *all)
{
  all->lum.vx = all->lum.x2;
  all->lum.vy = all->lum.y2;
  all->lum.vz = all->lum.z2;
}
