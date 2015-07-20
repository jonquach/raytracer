/*
** trans.c for trans in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:20 2014 frayss_c
** Last update Thu Jun  5 15:55:29 2014 
*/

#include <math.h>
#include "../include/rtv1.h"
#include "../include/prototype.h"

void	translate1(t_object *plan, t_spobject *eye)
{
  eye->tmpx = eye->x;
  eye->tmpy = eye->y;
  eye->tmpz = eye->z;
  eye->x = eye->x - plan->x;
  eye->y = eye->y - plan->y;
  eye->z = eye->z - plan->z;
}

void	translate2(t_object *plan, t_spobject *eye)
{
  /* plan->x = eye->tmpx - eye->x; */
  /* plan->y = eye->tmpy - eye->y; */
  /* plan->z = eye->tmpz - eye->z; */
  eye->x = eye->tmpx;
  eye->y = eye->tmpy;
  eye->z = eye->tmpz;
}
