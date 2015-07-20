/*
** parser.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Mon May 26 15:30:48 2014 kauch_j
** Last update Tue Jun  3 15:07:56 2014 quach_a
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"
#include "rtv1.h"

char    *read_it(char *file)
{
  int   ret;
  char  *buffer;
  char  *all_file;
  int   i;
  int	fd;

  i = 1;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (put_error_char("Error : open failed\n"));
  if ((buffer = malloc(READ_SIZE + 1)) == NULL)
    return (put_error_char("Error : malloc failed\n"));
  if ((all_file = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  while ((ret = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[ret] = '\0';
      if ((all_file = realloc(all_file, READ_SIZE * i + 1)) == NULL)
        return (NULL);
      (i == 1) ? strcpy(all_file, buffer) : strcat(all_file, buffer);
      i++;
    }
  return (all_file);
}

int		get_size(char **tab)
{
  int		res;
  int		i;

  res = 0;
  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "<object>", 8) == 0)
	res++;
      i++;
    }
  return (res);
}

int		get_window(t_all *all, char *str)
{
  char		**tab;

  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  all->my.y_size = my_getnbr(tab[1]);
  all->my.x_size = my_getnbr(tab[2]);
  return (0);
}

int		init_struct(t_all *all, int max)
{
  int		i;

  i = 0;
  while (i < max)
    {
      all->objects[i].x = 0;
      all->objects[i].k = -1;
      all->objects[i].y = 0;
      all->objects[i].z = 0;
      all->objects[i].ray = 0;
      all->objects[i].xrot = 0;
      all->objects[i].yrot = 0;
      all->objects[i].zrot = 0;
      all->objects[i].type = 0;
      all->objects[i].bright = 0;
      all->objects[i].color[0] = 0;
      all->objects[i].color[1] = 0;
      all->objects[i].color[2] = 0;
      i++;
    }
  all->my.k_color = 0;
  all->my.x_size = 0;
  all->my.y_size = 0;
  /* all->eye.x = 0; */
  /* all->eye.y = 0; */
  /* all->eye.z = 0; */
  all->lum.x = 0;
  all->lum.y = 0;
  all->lum.z = 0;
  all->lum.color[0] = 255;
  all->lum.color[1] = 255;
  all->lum.color[2] = 255;
  return (0);
}

int		init_value(t_all *all, char **tab)
{
  if ((all->objects = malloc(sizeof(t_object) * 5)) == NULL)
    return (put_error_int("Error : malloc failed\n"));
  //init_struct(all, get_size(tab));
  write(1, "\n", 1);
  get_window(all, tab[0]);
  write(1, "Z", 1);
  get_name(all, tab[1]);
  write(1, "Q", 1);
  get_eye(all, tab[3]);
  write(1, "S", 1);
  init_get_object(all, tab + 5);
  write(1, "D", 1);
  init_get_light(all, tab + 5);
  write(1, "W", 1);
  /* printf("name %s eyex %G eyey%G eyez%G X%d Y%d\n", all->my.name, all->eye.x, all->eye.y, all->eye.z, all->my.x_size, all->my.y_size); */
  return (0);
}

int		main(int ac, char **av)
{
  t_all		all;
  char		**tab;
  char		*file;

  if (ac == 2)
    {
      if ((file = read_it(av[1])) == NULL)
	return (put_error_int("THIS GAME SUCKS\n"));
    }
  else
    return (put_error_int("RTFM ---> Usage : ./rt [XML]\n "));
  // my_putstr(file);
  //my_putstr("###################################################\n");
  if ((tab = my_str_to_wordtab(file, "\n")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if (init_value(&all, tab) == -1)
    return (put_error_int("Error : INIT_VALUE failed\n"));
  //all.my.k_color = 0;
  ///set_value(&all);
  init_raytracer(&all);
  return (0);
}
