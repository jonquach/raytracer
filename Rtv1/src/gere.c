/*
** gerekey.c for gerekey in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:10:18 2014 frayss_c
** Last update Sun Jun  8 22:00:28 2014 kauch_j
*/

#include <mlx.h>
#include <stdlib.h>
#include "pauvray.h"

int	gere_expose(t_all *all)
{
  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
                          all->my.img_ptr, 0, 0);
  return (0);
}

int	gere_key(int keycode)
{
  if (keycode == 65307)
    exit(1);
  return (0);
}
