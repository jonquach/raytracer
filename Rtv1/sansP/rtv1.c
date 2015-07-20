/*
** rtv1.c for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:11:13 2014 frayss_c
** Last update Tue Jun  3 15:54:34 2014 quach_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
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
       /* printf("all->my.data[%d] = %c\n", put, all->my.data[put]); */
       /* printf("all->my.data[%d] = %c\n", put + 1, all->my.data[put + 1]); */
       /* printf("all->my.data[%d] = %c\n", put + 2, all->my.data[put + 2 ]); */
    }
}

void		first_k(t_all *all)
{
  int			i;
  int			tmp;

  tmp = 0;
  i = 0;
  while (all->objects[i].k)
    {
      if (all->objects[tmp].k < 0)
	{
	  printf("if tmp %d = i = %d\n", tmp, i);
	  printf("type i = %d\n", all->objects[i].type);
	  tmp = i;
	}
      else if (all->objects[i].k < all->objects[tmp].k
	       && all->objects[i].k > 0)
	{
	  printf("else if tmp %d = i = %d\n", tmp, i);
	  tmp = i;
	}
      i++;
    }
  if (all->objects[tmp].k < 0)
    {
      all->my.k_color = -1;
      //      printf("\ntmp = %d\n%G\n", tmp, all->objects[tmp].k);
    }
  else
    all->my.k_color = tmp;
  //bin/ printf("k = %d\n", all->my.k_color);
  //  exit(0);
}

void		all_objects(t_all *all)
{
  int		i;

  i = 0;
  while (all->objects[i].type != 0)
    {
      if (all->objects[i].type == SPHERE)
	{
	  /* printf("%d\n", i); */
	  /* printf("to the sphere =====================================\n"); */
	  inter_sphere(all, &all->objects[i]);
	}
      if (all->objects[i].type == PLAN)
	inter_plan(all, &all->objects[i]);
      if (all->objects[i].type == CYLINDER)
	inter_cyl(all, &all->objects[i]);
      if (all->objects[i].type == CONE)
	inter_cone(all, &all->objects[i]);
      i++;
    }
  /* int j; */
  /* j = 0; */
  /* while (j < 3)                                                                          */
  /*   { */
  /*     printf("......................................\n"); */
  /*     printf("x %G\n", all->objects[j].x); */
  /*     printf("y %G\n", all->objects[j].y); */
  /*     printf("z %G\n", all->objects[j].z); */
  /*     printf("ray %G\n", all->objects[j].ray); */
  /*     printf("xrot %G\n", all->objects[j].xrot); */
  /*     printf("yrot %G\n", all->objects[j].yrot); */
  /*     printf("zrot %G\n", all->objects[j].zrot); */
  /*     printf("type %d\n", all->objects[j].type); */
  /*     printf("bright %G\n", all->objects[j].bright); */
  /*     printf("color R %d\n", all->objects[j].color[0]); */
  /*     printf("color G %d\n", all->objects[j].color[1]); */
  /*     printf("color B %d\n", all->objects[j].color[2]); */
  /*     j++; */
  /*   } */
  first_k(all);
}

void		pixel_by_pixel(t_all *all)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  /* int j; */
  /* j = 0; */
  /* while (j < 3)                                                                          */
  /*   { */
  /*     printf("+++++++++++++++++++++++++++++++++++++\n"); */
  /*     printf("x %G\n", all->objects[j].x); */
  /*     printf("y %G\n", all->objects[j].y); */
  /*     printf("z %G\n", all->objects[j].z); */
  /*     printf("ray %G\n", all->objects[j].ray); */
  /*     printf("xrot %G\n", all->objects[j].xrot); */
  /*     printf("yrot %G\n", all->objects[j].yrot); */
  /*     printf("zrot %G\n", all->objects[j].zrot); */
  /*     printf("type %d\n", all->objects[j].type); */
  /*     printf("bright %G\n", all->objects[j].bright); */
  /*     printf("color R %d\n", all->objects[j].color[0]); */
  /*     printf("color G %d\n", all->objects[j].color[1]); */
  /*     printf("color B %d\n", all->objects[j].color[2]); */
  /*     j++; */
  /*   } */
  while (y <= all->my.y_size)
    {
      while (x <= all->my.x_size)
	{
	  //  printf(" WHERE THE X IS !!!!!! = %d\n", x);
	  all->eye.vx = 1000;
	  all->eye.vy = (all->my.x_size / 2) - x;
	  all->eye.vz = (all->my.y_size / 2) - y;
	  calc(x, y, all);
	  all_objects(all);
	  x++;
	}
      if (y <= all->my.y_size)
	{
	  //	  printf(" WHERE THE Y IS !!!!!! = %d\n", y);
	  y++;
	  x = 0;
	}
    }
}

int		init_raytracer(t_all *all)
{
  /* t_all		all; */

  all->objects = malloc(sizeof(t_object) * 5);
  all->my.k_color = 0;
  set_color(all);
  set_value(all);
  /* my_putstr("------------------------------------------------------------------------>\n"); */
  /* int j; */
  /* j = 0; */
  /* while (j < 3) */
  /*   { */
  /*     printf("BONJOUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUR\n"); */
  /*     printf("x %G\n", all->objects[j].x); */
  /*     printf("y %G\n", all->objects[j].y); */
  /*     printf("z %G\n", all->objects[j].z); */
  /*     printf("ray %G\n", all->objects[j].ray); */
  /*     printf("xrot %G\n", all->objects[j].xrot); */
  /*     printf("yrot %G\n", all->objects[j].yrot); */
  /*     printf("zrot %G\n", all->objects[j].zrot); */
  /*     printf("type %d\n", all->objects[j].type); */
  /*     printf("bright %G\n", all->objects[j].bright); */
  /*     printf("color R %d\n", all->objects[j].color[0]); */
  /*     printf("color G %d\n", all->objects[j].color[1]); */
  /*     printf("color B %d\n", all->objects[j].color[2]); */
  /*     j++; */
  /*   } */
  check_error(all);
  pixel_by_pixel(all);
  mlx_key_hook(all->my.win_ptr , gere_key, all);
  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
			  all->my.img_ptr, 0, 0);
  mlx_expose_hook(all->my.win_ptr , gere_expose, all);
  mlx_loop(all->my.mlx_ptr);
  return (0);
}
