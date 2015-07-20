/*
** texture_map_sphere.c for texture in /home/guiho_r/tek1/rt/src/texture
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May 15 16:47:21 2012 ronan guiho
** Last update Sat May 31 17:44:41 2014 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "utils.h"
#include "calc.h"
#include "image.h"
#include "texture.h"
#include "object.h"

/* int		texture_mapping_sphere(t_object *obj, t_color *color, */
/* 				       double *old_pos, t_image *image) */
/* { */
/*   double	rayon; */
/*   double	utils[3]; */
/*   int		texture[2]; */
/*   double	pos[3]; */

/*   modif_position(old_pos, obj, pos, INVERSE_ROTATION); */
/*   rayon = (double)((t_sphere *)obj->son)->radius; */
/*   utils[U] = atan(pos[Y] / pos[X]); */
/*   utils[V] = asin(pos[Z] / rayon); */
/*   utils[V] += M_PI; */
/*   utils[T] = (double)((image != NULL) ? image->freq : obj->perlin->freq) * \ */
/*     (utils[U] / M_PI + 0.5); */
/*   texture[Y] = ABS((int)(((image != NULL) ? image->size[HEIGHT] : SIZE_Y) * \ */
/* 			 (utils[T] - (int)utils[T]))); */
/*   utils[T] = 0.5 * (double)(image != NULL ? image->freq : \ */
/* 			    obj->perlin->freq) * utils[V] / M_PI; */
/*   texture[X] = ABS((int)(((image != NULL) ? image->size[WIDTH] :  SIZE_X) * \ */
/* 			 (utils[T] - (int)utils[T]))); */
/*   texture[X] = texture[X] % ((image != NULL) ? image->size[WIDTH] : SIZE_X); */
/*   texture[Y] = texture[Y] % ((image != NULL) ? image->size[HEIGHT] : SIZE_Y); */
/*   obj->texture_pos[X] = texture[X]; */
/*   obj->texture_pos[Y] = texture[Y]; */
/*   if (image != NULL) */
/*     texture_getcolor(image, color, texture); */
/*   return (EXIT_SUCCESS); */
/* } */
