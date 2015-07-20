/*
** main.c for main.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 19:07:01 2014 han_d
** Last update Sun Jun  8 22:18:53 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "pauvray.h"
#include "lib.h"

void	init_raytracer(t_all *all, char *file)
{
  check_error(all);
  my_putstr("\033[36mcreating image:\033[37m");
  if (import_jpg(file, all) == -1)
    exit(0);
  pixel_per_pixel(all);
  mlx_key_hook(all->my.win_ptr , gere_key, all);
  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
			  all->my.img_ptr, 0, 0);
  mlx_expose_hook(all->my.win_ptr , gere_expose, all);
  my_putstr("\033[32m Done!\n\033[0m");
  mlx_loop(all->my.mlx_ptr);
}

int	main(int ac, char **av)
{
  t_all	all;
  char	**tab;
  char	*file;

  if (ac == 2 || ac == 3)
    {
      if ((file = read_file(av[1])) == NULL)
	return (put_error_int("THIS GAME SUCKS\n"));
    }
  else
    return (put_error_int("RTFM ---> Usage : ./rt [XML]\n"));
  if ((tab = my_str_to_wordtab(file, "\n")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if (init_value(&all, tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_putstr("\033[36mreading file: \033[32mDone!\n\033[37m");
  init_raytracer(&all, av[2]);
  return (0);
}
