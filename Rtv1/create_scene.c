/*
** create_scene.c for create_scene.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 15:12:45 2014 han_d
** Last update Sat Jun  7 15:12:45 2014 han_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "rtv1.h"
#include "rt.h"

void		calc(int x, int y, t_all *all)
{
  int		put;

  put = all->my.x_size * y * 4 + x * 4;
  if (all->my.k_color == -1)
    {
      all->my.data[put] = 0;
      all->my.data[put + 1] = 0;
      all->my.data[put + 2] = 0;
    }
  else
    {
      all->my.data[put] = all->objects[all->my.k_color].color_tmp[0];
      all->my.data[put + 1] = all->objects[all->my.k_color].color_tmp[1];
      all->my.data[put + 2] = all->objects[all->my.k_color].color_tmp[2];
    }
}

void		first_k(t_all *all)
{
  int		i;
  int		tmp;

  i = 0;
  tmp = 0;
  while (i < all->nb_obj)
    {
      if (all->objects[tmp].k < 0)
	tmp = i;
      else if (all->objects[i].k < all->objects[tmp].k
	       && all->objects[i].k > 0)
	tmp = i;
      i++;
    }
  if (all->objects[tmp].k < 0.00001)
    all->my.k_color = -1;
  else
    all->my.k_color = tmp;
}

void		all_objects(t_all *all)
{
  int		i;

  i = 0;
  while (i < all->nb_obj)
    {
      if (all->objects[i].type == SPHERE)
	inter_sphere(all, &all->objects[i]);
      if (all->objects[i].type == PLAN)
	inter_plan(all, &all->objects[i]);
      if (all->objects[i].type == CYLINDER)
	inter_cyl(all, &all->objects[i]);
      if (all->objects[i].type == CONE)
	inter_cone(all, &all->objects[i]);
      //      printf("i = %d, k = %G", i, all->objects[i].k);
      i++;
    }
  first_k(all);
}

void		display_progress(int y, int y_size)
{
  static int	progress_value = -1;

  if ((y / (y_size / 100)) > progress_value && progress_value < 100)
    {
      ++progress_value;
      my_putstr("\033[33m");
      if (progress_value > 0 && progress_value < 101)
	my_putstr("\b\b\b\b");
      if (progress_value < 10)
	my_putstr(" 0");
      else
      	my_putchar(' ');
      my_putnbr(progress_value);
      my_putchar('%');
      my_putstr("\033[37m");
    }
}

void		pixel_per_pixel(t_all *all)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y <= all->my.y_size)
    {
      display_progress(y, all->my.y_size);
      while (x <= all->my.x_size)
	{
	  all->eye.vx = 1000;
	  all->eye.vy = (all->my.x_size / 2) - x;
	  all->eye.vz = (all->my.y_size / 2) - y;
	  calc(x, y, all);
	  all_objects(all);
	  ++x;
	}
      if (y <= all->my.y_size)
	{
	  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
				  all->my.img_ptr, 0, 0);
	  ++y;
	  x = 0;
	}
    }
}
