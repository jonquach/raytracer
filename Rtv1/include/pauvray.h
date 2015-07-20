/*
** pauvray.h for pauvray in /home/frayss_c/RT
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 21:16:21 2014 frayss_c
** Last update Sun Jun  8 22:21:50 2014 frayss_c
*/

#ifndef		PAUVRAY_H_
# define	PAUVRAY_H_

# define	READ_SIZE 4096
# define	SPHERE 1
# define	PLAN 2
# define	CYLINDER 3
# define	CONE 4

#include "obj.h"

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
  int		k_color;
}		t_coord;

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

typedef struct	s_tmp
{
  double	tmpx;
  double	tmpy;
  double	tmpz;
  double	color1;
  double	color2;
  double	color3;
}		t_tmp;

typedef struct	s_normal
{
  double	normx;
  double	normy;
  double	normz;
  double	pointx;
  double	pointy;
  double	pointz;
  double	cos;
  double	a1;
  double	a2;
}               t_normal;

typedef struct	s_all
{
  t_coord	my;
  t_object	*objects;
  t_tmp		tmp;
  t_spobject	*light;
  t_spobject	eye;
  t_spobject	lum;
  t_normal	norm;
  double	ambiance;
  int		nb_obj;
  int		nb_lights;
}		t_all;

/*
** create_scene.c
*/

void		calc(int, int, t_all *);
void		first_k(t_all *);
void		all_objects(t_all *);
void		display_progress(int, int);
void		pixel_per_pixel(t_all *);

/*
** effect_check.c
*/

void		effect_check_2(int, int, t_object *);
void		effect_check(t_all *, t_object *);

/*
** gere.c
*/

int		gere_expose(t_all *);
int		gere_key(int);

/*
** get_light.c
*/

void		get_light_param_value(t_spobject *, char **, int);
char		**create_light_list();
int		get_light_param(t_spobject *, char **);
void		init_get_light(t_all *, char **);

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

void		get_object_param_values_2(t_all *, char **, int, int);
void		get_object_param_values(t_all *, char **, int, int);

/*
** init_values.c
*/

char		*read_file(char *);
void		init_struct(t_all *, int);
int		init_value(t_all *, char **);

/*
** limit_object.c
*/

double		limit_cone_up(t_all *, t_object *);
double		limit_cone_down(t_all *, t_object *);
double		limit_cone_double(t_all *, t_object *);

/*
** limit_shadow.c
*/

t_inter		*limit_shadow_cone_up(t_object *, t_spobject *, t_inter *);
t_inter		*limit_shadow_cone_down(t_object *, t_spobject *, t_inter *);
t_inter		*limit_shadow_cone_double(t_object *, t_spobject *, t_inter *);

/*
** mlx_error.c
*/

void		my_mlx_init(t_all *);
void		my_mlx_new_window(t_all *);
void		my_mlx_new_image(t_all *);
void		my_mlx_get_data_addr(t_all *);
void		check_error(t_all *);

/*
** my_cos.c
*/

void		my_cos_2(t_all *, t_object *, t_spobject *);
void		my_cos(t_all *, double, t_object *, t_spobject *);

/*
** my_normal.c
*/

void		my_normal_2(t_all *, t_object *);
void		my_normal(t_all *, t_object *);

/*
** put_error.c
*/

char		*put_error_char(char *);
int		put_error_int(char *);

/*
** translate.c
*/

void		translate1(t_object *, t_spobject *);
void		translate2(t_object *, t_spobject *);

/*
** verif_nb_param.c
*/

void		bad_init(char *);
void		verif_nb_param(char **, int);

/*
** each function is in his own file (.c)
*/

/*
** calc_color.c
*/

void		calc_color(t_object *, t_all *);

/*
** init_shadow.c
*/

void		calc_lum_vector(t_all *, t_object *, int, t_spobject *);

int		get_ambiance(t_all *, char *);
int		get_size(char **);
int		get_window(t_all *, char *);
int		get_eye(t_all *, char **);
int		get_name(t_all *, char *);

/*
** main.c
*/

void		init_raytracer(t_all *, char*);
int		main(int, char **);
int		import_jpg(char *, t_all *);

#endif		/* !PAUVRAY_H_ */
