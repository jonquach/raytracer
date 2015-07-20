/*
** main.c for main.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sat Jun  7 19:07:01 2014 han_d
** Last update Sun Jun  8 23:28:49 2014 quach_a
*/

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "pauvray.h"
#include "lib.h"

int	*init_tab(int *tab)
{
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(int) * 5)) == NULL)
    exit(0);
  while (i <= 5)
    tab[i++] = 0;
  return (tab);
}

void	verbose(t_all *all, int i, int *tab)
{
  while (++i < all->nb_obj)
    {
      if (all->objects[i].type == 1)
	tab[0] += 1;
      else if (all->objects[i].type == 2)
	tab[1] += 1;
      else  if (all->objects[i].type == 3)
	tab[2] += 1;
      else  if (all->objects[i].type == 4)
	tab[3] += 1;
    }
  my_putstr("\033[36mSphere: \033[37m");
  my_putnbr(tab[0]);
  my_putstr("\033[36m\nCone: \033[37m");
  my_putnbr(tab[3]);
  my_putstr("\033[36m\nCylinder: \033[37m");
  my_putnbr(tab[2]);
  my_putstr("\033[36m\nPlan: \033[37m");
  my_putnbr(tab[1]);
  my_putstr("\033[36m\nLight: \033[37m");
  my_putnbr(all->nb_lights);
  my_putchar('\n');
}

void	init_raytracer(t_all *all, char *file)
{
  int	*tab;

  tab = 0;
  tab = init_tab(tab);
  check_error(all);
  my_putstr("\033[32m<--[ VERBOSE ]-->\n\033[0m");
  verbose(all, -1, tab);
  my_putstr("\033[36mcreating image:\033[37m");
  import_jpg(file, all);
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
	return (put_error_int("Error : file\n"));
    }
  else
    return (put_error_int("Usage : ./rt [XML] [JPEG]\n"));
  if ((tab = my_str_to_wordtab(file, "\n")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if (init_value(&all, tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_putstr("\033[36mreading file: \033[32mDone!\n\033[37m");
  init_raytracer(&all, av[2]);
  return (0);
}
