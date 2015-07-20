/*
** translate.c for translate in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/src
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sun Jun  8 21:47:59 2014 quach_a
** Last update Sun Jun  8 21:48:02 2014 quach_a
*/

#include <math.h>
#include "pauvray.h"

void	translate1(t_object *plan, t_spobject *eye)
{
  eye->x -= plan->x;
  eye->y -= plan->y;
  eye->z -= plan->z;
}

void	translate2(t_object *plan, t_spobject *eye)
{
  eye->x += plan->x;
  eye->y += plan->y;
  eye->z += plan->z;
}
