/*
** error.c for error in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:00 2014 frayss_c
** Last update Tue Jun  3 14:49:22 2014 kauch_j
*/

#include <stdlib.h>
#include <mlx.h>
#include "rtv1.h"
#include "rt.h"

void	check_error(t_all *all)
{
  if ((all->my.mlx_ptr = mlx_init()) == NULL)
    {
      my_putstr("mlx_init: ERROR\n");
      exit(0);
    }
  if ((all->my.win_ptr = mlx_new_window(all->my.mlx_ptr, all->my.x_size,
					all->my.y_size, "RTV1\n")) == NULL)
    {
      my_putstr("mlx_new_window: ERROR\n");
      exit(0);
    }
  if ((all->my.img_ptr = mlx_new_image(all->my.mlx_ptr, all->my.x_size,
				       all->my.y_size)) == NULL)
    {
      my_putstr("mlx_new_image: ERROR\n");
      exit(0);
    }
  if ((all->my.data =
       mlx_get_data_addr(all->my.img_ptr, &(all->my.bpp),
			 &(all->my.size_l), &(all->my.endian))) == NULL)
    {
      my_putstr("mlx_get_data_addr: ERROR\n");
      exit(0);
    }
}
