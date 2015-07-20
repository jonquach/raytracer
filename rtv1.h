/*
** rtv1.h for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 21:16:21 2014 frayss_c
** Last update Fri Jun  6 21:26:04 2014 han_d
*/

#ifndef		RTV1_H_
# define	RTV1_H_

/*
** object type
*/

# define	SPHERE	1
# define	PLAN	2
# define	CYLIND	3
# define	CONE	4

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
  double	k[100];
  int		count;
  char		*data;
  char		*name;
  float		coef;
  int		color[5][3];
  int		k_color;
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

typedef struct	s_object
{
  double       	x;
  double	x2;
  double       	y;
  double       	y2;
  double       	z;
  double       	z2;
  double	ray;
  double	k;
  double	bright;
  double	transparency;
  double       	tmpx;
  double       	tmpy;
  double       	tmpz;
  double	xrot;
  double	yrot;
  double	zrot;
  double	angle;
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
  t_object	v;
  t_object	*lum;
  t_object	eye;
  int		color[5][3];
  t_normal	n;
}		t_all;

int		gere_expose(t_all *);
int		gere_key(int);

/*
** set.c
*/

void		set_value(t_all *);
void		set_plan(t_all *, int);
void		set_sphere(t_all *, int);
void		set_sphere1(t_all *, int);
void		set_cone(t_all *, int);
void		set_cyl(t_all *, int);
double		my_getnbr_double(char *);

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
** moves.c
*/

void		rotate(t_all *, t_object *);
void		rotationx(t_all *, t_object *);
void		rotationy(t_all *, t_object *);
void		rotationz(t_all *, t_object *);
void		unrotate(t_all *);

/*
** trans.c
*/

void		translate1(t_object *, t_object *);
void		translate2(t_object *, t_object *);
void		my_normal(t_all *, int);
void		my_cos(t_all *, double, int, t_object *);
void		check_error(t_all *);
void		my_putchar(char);
//void		my_putstr(char *);
void		my_check_error(t_all *);
int		main();

#endif		/* !RTV1_H_ */
