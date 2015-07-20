/*
** rotate.h for rotate.h in /home/frayss_c/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Jun  8 18:23:17 2014 frayss_c
** Last update Sun Jun  8 19:22:50 2014 frayss_c
*/

#ifndef		ROTATE_H_
# define	ROTATE_H_

#include "obj.h"

/*
** rotate_eye.c
*/

void		rotationeyex(t_spobject *, t_spobject *);
void		rotationeyey(t_spobject *, t_spobject *);
void		rotationeyez(t_spobject *, t_spobject *);

/*
** rotate_unrotate.c
*/

void		protate(t_spobject *, t_object *);
void		punrotate(t_spobject *);
void		rotate(t_spobject *, t_object *);
void		unrotate(t_spobject *);
void		rotate_eye(t_spobject *, t_spobject *);

/*
** rotation.c
*/

void		rotationx(t_spobject *, t_object *);
void		rotationy(t_spobject *, t_object *);
void		rotationz(t_spobject *, t_object *);

/*
** rotation_point.c
*/

void		protationx(t_spobject *, t_object *);
void		protationy(t_spobject *, t_object *);
void		protationz(t_spobject *, t_object *);

#endif		/* !ROTATE_H_ */
