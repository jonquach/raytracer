/*
** obj.h for obj.h in /home/frayss_c/RT/tmp/tmp
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Fri Jun  6 11:18:15 2014 frayss_c
** Last update Sun Jun  8 21:34:50 2014 quach_a
*/

#ifndef		OBJ_H_
# define	OBJ_H_

typedef struct	s_spobject
{
  double	x;
  double	y;
  double	z;
  double	xrot;
  double	yrot;
  double	zrot;
  double	x2;
  double	y2;
  double	z2;
  double	vx;
  double	vy;
  double	vz;
  double	tmpx;
  double	tmpy;
  double	tmpz;
  int		color[3];
}		t_spobject;

typedef struct	s_object
{
  int		x;
  int		y;
  int		z;
  int		zbis;
  int		up;
  int		limit1;
  int		limit2;
  double	ray;
  double	k;
  double	bright;
  double	xrot;
  double	yrot;
  double	zrot;
  double	angle;
  int		trouble;
  int		check;
  int		color_check[3];
  int		color[3];
  int		color_tmp[3];
  int		type;
}               t_object;

#endif		/* !OBJ_H_ */
