/*
** parser.c for parser.c in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Mon May 26 15:30:48 2014 kauch_j
** Last update Sat Jun  7 13:56:38 2014 han_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"
#include "rtv1.h"

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
      ++i;
    }
  return (all_file);
}
