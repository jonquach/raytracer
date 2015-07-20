/*
** rtv1.h for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 21:16:21 2014 frayss_c
** Last update Thu Jun  5 14:59:58 2014 
*/

#ifndef		PROTOTYPE_H_
# define	PROTOTYPE_H_

int		gere_expose(t_all *all);
int		gere_key(int keycode);

/*
** set.c
*/

void		set_value(t_all *all);
void		set_plan(t_all *all, int);
void		set_sphere(t_all *all, int);
void		set_sphere1(t_all *all, int);
void		set_cone(t_all *all, int);
void		set_cyl(t_all *all, int);

/*
** set_color.c
*/

void		set_color(t_all *all);

/*
** inter.c
*/

void		inter_sphere(t_all *all, t_object *sphere);
void		inter_cyl(t_all *all, t_object *sphere);
void		inter_plan(t_all *all, t_object *sphere);
void		inter_cone(t_all *all, t_object *sphere);

/*
** shadow.c
*/

int		inter_sphere_shadow(t_all *all, t_object *sphere);
int		inter_cyl_shadow(t_all *all, t_object *cyl);
int		inter_plan_shadow(t_all *all, t_object *plan);
int		inter_cone_shadow(t_all *all, t_object *cone);
void		calc_lum_vector(t_all *all, t_object *object);

/*
** moves.c
*/

void		rotate(t_all *all, t_object *object);
void		rotatel(t_all *all, t_object *object);
void		rotationx(t_all *all, t_object *object);
void		rotationy(t_all *all, t_object *object);
void		rotationz(t_all *all, t_object *object);
void		rotationxl(t_all *all, t_object *object);
void		rotationyl(t_all *all, t_object *object);
void		rotationzl(t_all *all, t_object *object);
void		unrotate(t_all *all);
void		unrotatel(t_all *all);

/*
** trans.c
*/

void		translate1(t_object *plan, t_spobject *eye);
void		translate2(t_object *plan, t_spobject *eye);
void		my_normal(t_all *all, int obj);
void		my_cos(t_all *all, double k, int obj, t_object *object);
void		check_error(t_all *all);
void		my_putchar(char);
void		my_check_error(t_all *all);
double		my_getnbr_double(char *);

#endif		/* !PROTOTYPE_H_ */
