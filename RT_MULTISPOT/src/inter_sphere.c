/*
** inter_sphere.c for inter_sphere.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:35:33 2014 han_d
** Last update Sun Jun  8 21:54:20 2014 kauch_j
*/

#include <math.h>
#include "pauvray.h"
#include "inter.h"

void		find_tmp_color(t_all *all, t_object *obj, int index, double k)
{
  int		l;

  obj->k = k;
  all->tmp.color1 = 0;
  all->tmp.color2 = 0;
  all->tmp.color3 = 0;
  l = 0;
  while (l < all->nb_lights)
    {
      my_cos(all, k, obj, &all->light[l]);
      calc_lum_vector(all, obj, index, &all->light[l]);
      l++;
      all->tmp.color1 += obj->color_tmp[0];
      all->tmp.color2 += obj->color_tmp[1];
      all->tmp.color3 += obj->color_tmp[2];
    }
}

void		inter_sphere(t_all *all, t_object *obj, int index)
{
  t_inter	i;

  translate1(obj, &all->eye);
  i.a = pow(all->eye.vx, 2) + pow(all->eye.vy, 2) + pow(all->eye.vz, 2);
  i.b = 2 * (all->eye.x * all->eye.vx + all->eye.y
	     * all->eye.vy + all->eye.z * all->eye.vz);
  i.c = all->eye.x * all->eye.x + all->eye.y *
    all->eye.y + all->eye.z * all->eye.z - obj->ray * obj->ray;
  i.delta = i.b * i.b - 4 * i.a * i.c;
  i.k = (-i.b - sqrt(i.delta)) / (2 * i.a);
  i.k2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
  if (i.k < i.k2 && i.k > 0.00001)
    find_tmp_color(all, obj, index, i.k);
  else if (i.k2 < i.k && i.k2 > 0.00001)
    find_tmp_color(all, obj, index, i.k2);
  translate2(obj, &all->eye);
  if (i.delta <= 0)
    obj->k = -1;
  calc_color(obj, all);
}
