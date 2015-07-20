/*
** parser.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Mon May 26 15:30:48 2014 kauch_j
** Last update Sat May 31 14:41:37 2014 quach_a
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
  int		i;
  char		**tab;

  i = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  all->my.y_size = my_getnbr(tab[1]);
  all->my.x_size = my_getnbr(tab[2]);
}

int		init_struct(t_all *all, int max)
{
  int		i;

  i = 0;
  while (i < max)
    {
      all->objects[i].x = 0;
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
}

int		init_value(t_all *all, char **tab)
{
  char		*str;

  if ((all->objects = malloc(sizeof(t_object) * get_size(tab))) == NULL)
    return (put_error_int("Error : malloc failed\n"));
  init_struct(all, get_size(tab));
  get_window(all, tab[0]);
  get_name(all, tab[1]);
  get_eye(all, tab[3]);
  init_get_object(all, tab + 5);
  init_get_light(all, tab + 5);
  /* printf("name %s eyex %G eyey%G eyez%G X%d Y%d\n", all->my.name, all->eye.x, all->eye.y, all->eye.z, all->my.x_size, all->my.y_size); */
}

int		main(int ac, char **av)
{
  t_all		all;
  int		size;
  char		**tab;
  char		*file;

  if (ac > 1 && ac < 3)
    if ((file = read_it(av[1])) == NULL)
      return (put_error_int("THIS GAME SUCKS\n"));
  my_putstr(file);
  my_putstr("###################################################\n");
  if ((tab = my_str_to_wordtab(file, "\n")) == NULL)
    return (put_error_int("Error : STR_TO_WORDTAB failed\n"));
  if (init_value(&all, tab) == -1)
    return (put_error_int("Error : INIT_VALUE failed\n"));
}
