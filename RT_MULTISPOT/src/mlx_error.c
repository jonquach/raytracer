/*
** error.c for mlx_error.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/src
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 20:15:13 2014 han_d
** Last update Sun Jun  8 22:09:02 2014 quach_a
*/

#include <stdlib.h>
#include <mlx.h>
#include "pauvray.h"
#include "lib.h"

void	my_mlx_init(t_all *all)
{
  my_putstr("\033[36mmlx_init: \033[37m");
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
  my_putstr("\033[36mmlx_new_window: \033[37m");
  if ((all->my.win_ptr = mlx_new_window(all->my.mlx_ptr, all->my.x_size,
                                        all->my.y_size,
					all->my.name)) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    my_putstr("\033[32mDone!\n\033[37m");
}

void	my_mlx_new_image(t_all *all)
{
  my_putstr("\033[36mmlx_new_image: \033[37m");
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
  my_putstr("\033[36mmlx_get_data_addr: \033[37m");
  if ((all->my.data =
       mlx_get_data_addr(all->my.img_ptr, &(all->my.bpp),
                         &(all->my.size_l), &(all->my.endian))) == NULL)
    {
      my_putstr("\033[31mERROR\n\033[37m");
      exit(EXIT_FAILURE);
    }
  else
    {
      my_putstr("\033[32mDone!\033[37m");
      my_putstr("\033[0m\n");
    }
}

void	check_error(t_all *all)
{
  my_mlx_init(all);
  my_mlx_new_window(all);
  my_mlx_new_image(all);
  my_mlx_get_data_addr(all);
}
