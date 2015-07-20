/*
** tore.c for tore.c in /home/rechou_f/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by fabien rechou
** Login   <rechou_f@epitech.net>
** 
** Started on  Fri Jun  6 19:17:18 2014 fabien rechou
** Last update Sat Jun  7 15:15:16 2014 han_d
*/

#include "rtv1.h"

void		tore_var(t_all *all)
{
  double	R;
  double	r;

  R = 200;
  r = 50;
  all->tore.x = 400;
  all->tore.y = -400;
  all->tore.z = 600;
  all->tore.a = pow(1 + (all->eye.vy / 500 * all->eye.vy / 500)
		    + (all->eye.vz / 500 * all->eye.vz / 500), 2);
  all->tore.b = 4 * (1 + (all->eye.vy / 500 * all->eye.vy / 500)
		     + (all->eye.vz / 500 * all->eye.vz / 500))
    * (1 * all->tore.x + all->eye.vy / 500
       * all->tore.y + all->eye.vz / 500 * all->tore.z);
  all->tore.c = 2 * (1 + (pow(all->eye.vy / 500, 2))
		     + (pow(all->eye.vz / 500, 2)) *
		     (pow(all->tore.x, 2) + pow(all->tore.y, 2)
		      + pow(all->tore.z, 2) + R * R - r * r)
		     + pow(all->tore.x + all->eye.vy / 500 * all->tore.y
			   + all->eye.vz / 500 * all->tore.z, 2) - 4 * R * R
		     * (all->eye.vz / 500 * all->tore.z));
  all->tore.d = 4 * (all->tore.x + all->eye.vy / 500 * all->tore.y
		     + all->eye.vz / 500 * all->tore.z)
    * (pow(all->tore.x, 2) + pow(all->tore.y, 2) + pow(all->tore.z, 2)
       + R * R - r * r) -
    (8 * R * R * (all->tore.x + all->tore.z * all->eye.vz / 500));
  all->tore.e = pow(pow(all->tore.x, 2) + pow(all->tore.y, 2)
		    + pow(all->tore.z, 2) + R * R - r * r, 2)
    - (4 * R * R * (pow(all->tore.x, 2) * pow(all->tore.z, 2)));
}

void		tore(t_all *all)
{
  double	a;
  double	b;
  double	u;
  double	x;
  double	z;

  u = 0;
  tore_var(all);
  a = -(3 * pow(all->tore.b, 2)) / 8 * pow(all->tore.a, 2) + all->tore.c /
    all->tore.a;
  b = pow((all->tore.b / 2), 3) / pow(all->tore.a, 3)
    - (1 / 2 * all->tore.b * all->tore.c / pow(all->tore.a, 2))
    + all->tore.d / all->tore.a;
  x = -(all->tore.b / 4 * all->tore.a);
  z = b / 2 * (u - a);
  if (b != 0)
    while ((pow(pow(x, 2) + u / 2, 2)) < ((u - a) * pow((x - z), 2)))
      u = u - 100000;
  //  printf("%f, %f, %f,\n", u, (pow(pow(x, 2) + u / 2, 2)),(u - a) * pow((x - z), 2));
}
