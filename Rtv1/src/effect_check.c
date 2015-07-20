/*
** effet_check.c for effet_check in /home/lin_c/Dropbox/EPITECH_PROJECT/Raytracer/RT_MULTISPOT
** 
** Made by 
** Login   <lin_c@epitech.net>
** 
** Started on  Sat Jun  7 19:18:01 2014 
** Last update Sun Jun  8 21:46:18 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"

void	effect_check_2(int px, int py, t_object *object)
{
  if (((py % 100 > 50 && px % 100 < -50) ||
	    (py % 100 < 50 && px % 100 > -50)) && py >= 0 && px < 0)
    {
      object->color_tmp[0] = object->color_check[0];
      object->color_tmp[1] = object->color_check[1];
      object->color_tmp[2] = object->color_check[2];
    }
  else if (((py % 100 < -50 && px % 100 > 50) ||
	    (py % 100 > -50 && px % 100 < 50)) && py <= 0 && px > 0)
    {
      object->color_tmp[0] = object->color_check[0];
      object->color_tmp[1] = object->color_check[1];
      object->color_tmp[2] = object->color_check[2];
    }
}

void	effect_check(t_all *all, t_object *object)
{
  int	px;
  int	py;

  px = (int)all->norm.pointx;
  py = (int)all->norm.pointy;
  if (((px % 100 > 50 && py % 100 < 50) ||
       (px % 100 < 50 && py % 100 > 50)) && py > 0 && px > 0)
    {
      object->color_tmp[0] = object->color_check[0];
      object->color_tmp[1] = object->color_check[1];
      object->color_tmp[2] = object->color_check[2];
    }
  else if (((py % 100 > -50 && px % 100 < -50 ) ||
	    (py % 100 < -50 && px % 100 > -50)) && py < 0 && px < 0)
    {
      object->color_tmp[0] = object->color_check[0];
      object->color_tmp[1] = object->color_check[1];
      object->color_tmp[2] = object->color_check[2];
    }
  effect_check_2(px, py, object);
}
