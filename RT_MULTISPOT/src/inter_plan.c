/*
** inter_plan.c for inter_plan.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:35:15 2014 han_d
** Last update Sun Jun  8 21:53:30 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"
#include "inter.h"
#include "rotate.h"

void		inter_plan(t_all *all, t_object *obj, int index)
{
  double	k;

  translate1(obj, &all->eye);
  protate(&all->eye, obj);
  rotate(&all->eye, obj);
  if (all->eye.vz != 0)
    k = -all->eye.z / all->eye.vz;
  else
    k = -1;
  if (k > 0.00001)
    find_tmp_color(all, obj, index, k);
  else
    obj->k = -1;
  punrotate(&all->eye);
  translate2(obj, &all->eye);
  unrotate(&all->eye);
  calc_color(obj, all);
}
