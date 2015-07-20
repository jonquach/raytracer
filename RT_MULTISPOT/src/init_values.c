/*
** parser.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Mon May 26 15:30:48 2014 kauch_j
** Last update Sun Jun  8 21:51:37 2014 kauch_j
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pauvray.h"

char	*read_file(char *file)
{
  int	ret;
  char	*buffer;
  char	*all_file;
  int	i;
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

void	init_struct(t_all *all, int max)
{
  int	i;

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
}

int	init_value(t_all *all, char **tab)
{
  all->nb_obj = get_size(tab);
  if ((all->objects = malloc(sizeof(t_object) * get_size(tab))) == NULL)
    return (put_error_int("Error : malloc failed\n"));
  init_struct(all, get_size(tab));
  if (get_window(all, tab[0]) == -1)
    return (-1);
  if (get_name(all, tab[1]) == -1)
    return (-1);
  if (get_ambiance(all, tab[2]) == -1)
    return (-1);
  if (get_eye(all, tab + 4) == -1)
    return (-1);
  if (init_get_object(all, tab + 5) == -1)
    return (-1);
  init_get_light(all, tab + 5);
  return (0);
}
