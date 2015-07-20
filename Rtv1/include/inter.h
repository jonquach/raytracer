/*
** inter.h for inter.h in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/include
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:08:52 2014 han_d
** Last update Sun Jun  8 22:07:01 2014 frayss_c
*/

#ifndef		INTER_H_
# define	INTER_H_

#include "pauvray.h"

void		inter_cyl(t_all *, t_object *, int);
void		inter_plan(t_all *, t_object *, int);

/*
** inter_obj.c
*/

void		find_tmp_color(t_all *, t_object *, int, double);
void		inter_sphere(t_all *, t_object *, int);

/*
** inter_cone.c
*/

void		inter_cone2(t_all *, t_object *, t_inter *, int);
void		inter_cone(t_all *, t_object *, int);

/*
** shadow.c
*/

int		inter_sphere_shadow(t_object *, t_spobject *);
int		inter_cyl_shadow(t_object *, t_spobject *);
int		inter_cone_shadow_delta(t_inter *);
int		inter_cone_shadow(t_object *, t_spobject *);
int		inter_plan_shadow(t_object *, t_spobject *);

#endif		/* !INTER_H_ */
