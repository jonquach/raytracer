/*
** rtv1.c for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:11:13 2014 frayss_c
** Last update Tue Jun  3 15:03:02 2014 quach_a
*/

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "rtv1.h"

void		calc(int x, int y, t_all *all)
{
  int		put;

  all->v.x = 1000;
  all->v.y = (all->my.x_size / 2) - x;
  all->v.z = (all->my.y_size / 2) - y;
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
      printf("all->my.data[%d] = %c\n", put, all->my.data[put]);
      printf("all->my.data[%d] = %c\n", put + 1, all->my.data[put + 1]);
      printf("all->my.data[%d] = %c\n", put + 2, all->my.data[put + 2 ]);
    }
}

void		first_k(t_all *all)
{
  int			i;
  int			tmp;

  i = 0;
  tmp = 0;
  while (all->objects[i].k)
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
  while (all->objects[i].type)
    {
      if (all->objects[i].type == SPHERE)
	inter_sphere(all, &all->objects[i]);
      if (all->objects[i].type == PLAN)
	inter_plan(all, &all->objects[i]);
      if (all->objects[i].type == CYLINDER)
	inter_cyl(all, &all->objects[i]);
      if (all->objects[i].type == CONE)
	inter_cone(all, &all->objects[i]);
      i++;
    }
  first_k(all);
}

void		remplis_image(t_all *all)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y <= all->my.y_size)
    {
      while (x <= all->my.x_size)
	{
	  all->my.count = 1;
	  calc(x, y, all);
	  all_objects(all);
	  x++;
	}
      if (y <= all->my.y_size)
	{
	  y++;
	  x = 0;
	}
    }
}

int		main()
{
  t_all		all;

  all.objects = malloc(sizeof(t_object) * 5);
  set_color(&all);
  set_value(&all);
  check_error(&all);
  remplis_image(&all);
  mlx_key_hook(all.my.win_ptr , gere_key, &all);
  mlx_put_image_to_window(all.my.mlx_ptr, all.my.win_ptr,
			  all.my.img_ptr, 0, 0);
  mlx_expose_hook(all.my.win_ptr , gere_expose, &all);
  mlx_loop(all.my.mlx_ptr);
  return (0);
}
