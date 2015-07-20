/*
** shadow_management.c for raytracer in /home/leprov_a//depot/rt/src/shadow
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat May 12 01:35:14 2012 alexis leprovost
** Last update Sun Jun  8 10:26:30 2014 
*/

#include	<stdlib.h>
#include	"global.h"
#include	"detail.h"
#include	"color.h"
#include	"object.h"
#include	"init.h"

int
shadow_patch(t_camera *camera, double *position, t_obj_type flag)
{
  camera->position[X] = position[X];
  camera->position[Y] = position[Y];
  camera->position[Z] = position[Z];
  if (flag == PLAN)
    {
      camera->position[X] > 0.0F ? (camera->position[X] -= EPSILON) :
	(camera->position[X] += EPSILON);
      camera->position[Y] > 0.0F ? (camera->position[Y] -= EPSILON) :
	(camera->position[Y] += EPSILON);
      camera->position[Z] > 0.0F ? (camera->position[Z] -= EPSILON) :
	(camera->position[Z] += EPSILON);
    }
  return (EXIT_SUCCESS);
}

double
shadow_final(t_detail *detail, double *vector, double value)
{
  t_object	*object[3];
  t_camera	camera;

  object[0] = detail->object;
  while (object[0]->prev)
    object[0] = object[0]->prev;
  while (value)
    {
      object[2] = detail->object;
      shadow_patch(&camera, detail->position, detail->object->type);
      init_detail(detail);
      object[1] = object[0];
      while (object[1])
	{
	  if (object[2] != object[1])
	    object[1]->inter(&camera, object[1], detail, vector);
	  object[1] = object[1]->next;
	}
      if (detail->k > 0.0F && detail->k < 1.0F)
	value *= detail->object->effect[TRANSPARENCY];
      else
	return (value);
    }
  return (value);
}

double
shadow_management(t_detail *detail, t_color *color, double *vector)
{
  t_object	*tmp;
  t_detail	shadow;
  t_camera	camera;
  double	cst;

  if (detail == NULL || color == NULL || vector == NULL)
    return (0.0F);
  shadow_patch(&camera, detail->position, detail->object->type);
  tmp = detail->object;
  while (tmp->prev)
    tmp = tmp->prev;
  init_detail(&shadow);
  while (tmp)
    {
      tmp->inter(&camera, tmp, &shadow, vector);
      tmp = tmp->next;
    }
  color = color;
  if (shadow.k > CONST_ERROR && shadow.k < 1.0F)
    {
      cst = 1.0F * shadow.object->effect[TRANSPARENCY];
      cst = shadow_final(&shadow, vector, cst);
      return (cst);
    }
  return (1.0F);
}
