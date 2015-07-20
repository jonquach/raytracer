/*
** rtv1.h for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 21:16:21 2014 frayss_c
** Last update Sat Jun  7 11:49:19 2014 
*/

#ifndef		RTV1_H_
# define	RTV1_H_

# define	SPHERE 1
# define	PLAN 2
# define	CYLINDER 3
# define	CONE 4

typedef struct	s_coord
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  void		*img_ptr2;
  int		bpp;
  int		percent;
  int		size_l;
  int       	x_size;
  int		y_size;
  int		endian;
  int		count;
  char		*data;
  char		*name;
  float		coef;
  int		color[5][3];
  int		k_color;
  int		k_shadow;
}		t_coord;

typedef struct	s_normal
{
  double	nx;
  double	ny;
  double	nz;
  double	px;
  double	py;
  double	pz;
  double	cos;
  double	a1;
  double	a2;
}		t_normal;

typedef struct	s_inter
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	delta;
  double	k;
  double	k2;
}		t_inter;

typedef struct	s_transpa
{
  double	vx;
  double       	vy;
  double	vz;
}		t_transpa;

typedef struct	s_spobject
{
  double       	x;
  double	x2;
  double       	y;
  double       	y2;
  double       	z;
  double       	z2;
  double	vx;
  double	vy;
  double	vz;
  double       	tmpx;
  double       	tmpy;
  double       	tmpz;
  int		color[3];
}		t_spobject;

typedef struct	s_object
{
  double       	x;
  double       	y;
  double       	z;
  double	ray;
  double	k;
  double	k_lum;
  double	bright;
  double       	normx;
  double       	normy;
  double       	normz;
  double	xrot;
  double	yrot;
  double	zrot;
  double	angle;
  int		transparency;
  int		color[3];
  int		color_tmp[3];
  int		type;
}		t_object;

typedef struct	s_all
{
  t_coord	my;
  t_object	*objects;
  t_object	plan;
  t_object	sphere;
  t_object	cone;
  t_object	cyl;
  t_spobject	eye;
  t_spobject	lum;
  t_transpa	transpa;
  int		color[5][3];
  int		nb_obj;
  t_normal	n;
}		t_all;

/* int		gere_expose(t_all *all); */
/* int		gere_key(int keycode); */

/* /\* */
/* ** set.c */
/* *\/ */

/* void		set_value(t_all *all); */
/* void		set_plan(t_all *all, int); */
/* void		set_sphere(t_all *all, int); */
/* void		set_sphere1(t_all *all, int); */
/* void		set_cone(t_all *all, int); */
/* void		set_cyl(t_all *all, int); */

/* /\* */
/* ** set_color.c */
/* *\/ */

/* void		set_color(t_all *all); */

/* /\* */
/* ** inter.c */
/* *\/ */

/* void		inter_sphere(t_all *all, t_object *sphere); */
/* void		inter_cyl(t_all *all, t_object *sphere); */
/* void		inter_plan(t_all *all, t_object *sphere); */
/* void		inter_cone(t_all *all, t_object *sphere); */

/* /\* */
/* ** shadow.c */
/* *\/ */

/* int		inter_sphere_shadow(t_all *all, t_object *sphere); */
/* int		inter_cyl_shadow(t_all *all, t_object *cyl); */
/* int		inter_plan_shadow(t_all *all, t_object *plan); */
/* int		inter_cone_shadow(t_all *all, t_object *cone); */
/* void		calc_lum_vector(t_all *all, t_object *object); */

/* /\* */
/* ** moves.c */
/* *\/ */

/* void		rotate(t_all *all, t_object *object); */
/* void		rotatel(t_all *all, t_object *object); */
/* void		rotationx(t_all *all, t_object *object); */
/* void		rotationy(t_all *all, t_object *object); */
/* void		rotationz(t_all *all, t_object *object); */
/* void		rotationxl(t_all *all, t_object *object); */
/* void		rotationyl(t_all *all, t_object *object); */
/* void		rotationzl(t_all *all, t_object *object); */
/* void		unrotate(t_all *all); */
/* void		unrotatel(t_all *all); */

/* /\* */
/* ** trans.c */
/* *\/ */

/* void		translate1(t_object *plan, t_spobject *eye); */
/* void		translate2(t_object *plan, t_spobject *eye); */
/* void		my_normal(t_all *all, int obj); */
/* void		my_cos(t_all *all, double k, int obj, t_object *object); */
/* void		check_error(t_all *all); */
/* void		my_putchar(char); */
/* void		my_check_error(t_all *all); */
/* double		my_getnbr_double(char *); */

#endif		/* !RTV1_H_ */
