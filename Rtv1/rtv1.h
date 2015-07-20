/*
** rtv1.h for rtv1.h in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 21:16:21 2014 frayss_c
** Last update Sun Jun  8 18:33:22 2014 fabien rechou
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
  double       	px;
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
  double	zbis;
  double	up;
  double	limit1;
  double	limit2;
  double	ray;
  double	k;
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

int		gere_expose(t_all *);
int		gere_key(int);

/*
** set_objects.c
*/

void		set_value(t_all *);
void		set_plan(t_all *, int);
void		set_sphere(t_all *, int);
void		set_sphere1(t_all *, int);
void		set_cone(t_all *, int);
void		set_cyl(t_all *, int);

/*
** set_color.c
*/

void		set_color(t_all *);

/*
** inter.c
*/

void		inter_sphere(t_all *, t_object *);
void		inter_cyl(t_all *, t_object *);
void		inter_plan(t_all *, t_object *);
void		inter_cone(t_all *, t_object *);

/*
** shadow.c
*/

int		inter_sphere_shadow(t_all *, t_object *);
int		inter_cyl_shadow(t_all *, t_object *);
int		inter_plan_shadow(t_all *, t_object *);
int		inter_cone_shadow(t_all *, t_object *);
void		calc_lum_vector(t_all *, t_object *);
t_inter		limit_shadow_cone_up(t_all *, t_object *, t_inter *);
t_inter		limit_shadow_cone_down(t_all *, t_object *, t_inter *);
t_inter		limit_shadow_cone_double(t_all *, t_object *, t_inter *);

/*
** moves.c
*/

void		rotate(t_all *, t_object *);
void		rotatel(t_all *, t_object *);
void		rotationx(t_all *, t_object *);
void		rotationy(t_all *, t_object *);
void		rotationz(t_all *, t_object *);
void		rotationxl(t_all *, t_object *);
void		rotationyl(t_all *, t_object *);
void		rotationzl(t_all *, t_object *);
void		unrotate(t_all *);
void		unrotatel(t_all *);

/*
** trans.c
*/

void		translate1(t_object *, t_spobject *);
void		translate2(t_object *, t_spobject *);
void		my_normal(t_all *, t_object *);
void		my_cos(t_all *, double, t_object *);
void		check_error(t_all *);
void		my_putchar(char);
void		my_check_error(t_all *);
double		my_getnbr_double(char *);

/*
** get_object.c
*/

char		**create_param_list();
char		**create_type_list();
int		get_object_param(t_all *, char **, int);
int		get_object_type(t_all *, char **, int);
int		init_get_object(t_all *, char **);

/*
** get_object_param_values.c
*/

void		get_object_param_values(t_all *, char **, int, int);
void		get_object_param_values_2(t_all *, char **, int, int);

/*
** create_scene.c
*/

void		calc(int, int, t_all *);
void		first_k(t_all *);
void		all_objects(t_all *);
void		display_progress(int, int);
void		pixel_per_pixel(t_all *);

#endif		/* !RTV1_H_ */
