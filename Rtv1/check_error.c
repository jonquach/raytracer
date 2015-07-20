/*
** error.c for error in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:00 2014 frayss_c
** Last update Fri Jun  6 16:53:05 2014 han_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "rtv1.h"
#include "rt.h"

void	my_mlx_init(t_all *all)
{
  my_putstr("\033[36mmlx_init: ");
  if ((all->my.mlx_ptr = mlx_init()) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    my_putstr("\033[32mDone!\n\033[37m");
}

void	my_mlx_new_window(t_all *all)
{
  my_putstr("\033[36mmlx_new_window: ");
  if ((all->my.win_ptr = mlx_new_window(all->my.mlx_ptr, all->my.x_size,
					all->my.y_size, "RTV1\n")) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    my_putstr("\033[32mDone!\n\033[37m");
}

void	my_mlx_new_image(t_all *all)
{
  my_putstr("\033[36mmlx_new_image: ");
  if ((all->my.img_ptr = mlx_new_image(all->my.mlx_ptr, all->my.x_size,
				       all->my.y_size)) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    my_putstr("\033[32mDone!\n\033[37m");
}

void	my_mlx_get_data_addr(t_all *all)
{
  my_putstr("\033[36mmlx_get_data_addr: ");
  if ((all->my.data =
       mlx_get_data_addr(all->my.img_ptr, &(all->my.bpp),
			 &(all->my.size_l), &(all->my.endian))) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    my_putstr("\033[32mDone!\n\033[37m");
}

void	check_error(t_all *all)
{
  my_mlx_init(all);
  my_mlx_new_window(all);
  my_mlx_new_image(all);
  my_mlx_get_data_addr(all);
}
