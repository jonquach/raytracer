/*
** main.c for main.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/Rtv1
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 13:43:07 2014 han_d
** Last update Sat Jun  7 15:09:17 2014 han_d
*/

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "rtv1.h"

int	init_raytracer(t_all *all)
{
  all->my.k_color = 0;
  all->my.color[0][2] = 0;
  all->my.color[0][1] = 0;
  all->my.color[0][0] = 0;
  //  all->nb_light = 1;
  check_error(all);
  my_putstr("\033[36mcreating image:\033[37m");
  pixel_per_pixel(all);
  mlx_key_hook(all->my.win_ptr , gere_key, all);
  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
                          all->my.img_ptr, 0, 0);
  mlx_expose_hook(all->my.win_ptr , gere_expose, all);
  my_putstr("\033[32m Done!\n\033[37m");
  mlx_loop(all->my.mlx_ptr);
  return (0);
}

int	main(int ac, char **av)
{
  t_all	all;
  char	**tab;
  char	*file;

  if (ac == 2)
    {
      if ((file = read_file(av[1])) == NULL)
	return (put_error_int("THIS GAME SUCKS\n"));
    }
  else
    return (put_error_int("RTFM ---> Usage : ./rt [XML]\n "));
  if ((tab = my_str_to_wordtab(file, "\n")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if (init_value(&all, tab) == -1)
    return (put_error_int("Error : INIT_VALUE failed\n"));
  my_putstr("\033[36mreading file: \033[32mDone!\n\033[37m");
  init_raytracer(&all);
  return (0);
}
