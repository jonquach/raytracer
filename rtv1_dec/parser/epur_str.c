/*
** epur_str.c for epru in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May 31 16:28:45 2014 quach_a
** Last update Thu Jun  5 15:56:11 2014 
*/

#include <stdlib.h>
#include "../include/rt.h"
#include "../include/rtv1.h"
#include "../include/prototype.h"

char	*epur_strcpy(char *str, char *new_str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (find_char(str[i], " \t") == 0 && str[i] != '\0')
    ++i;
  while (str[i] != '\0')
    {
      while (find_char(str[i], " \t") == 1 && str[i] != '\0')
	new_str[j++] = str[i++];
      while (find_char(str[i], " \t") == 0 && str[i] != '\0')
	++i;
      if (str[i] != '\0')
	new_str[j++] = ' ';
    }
  new_str[j] = '\0';
  return (new_str);
}

char	*epur_str(char *str)
{
  char	*new_str;
  int	i;
  int	size;

  i = 0;
  size = 0;
  if (str == NULL)
    return (NULL);
  while (find_char(str[i], " \t") == 0 && str[i] != '\0')
    ++i;
  while (str[i] != '\0')
    {
      while (find_char(str[i], " \t") == 1 && str[i] != '\0')
	{
	  ++i;
	  ++size;
	}
      while (find_char(str[i], " \t") == 0 && str[i] != '\0')
	++i;
      ++size;
    }
  if ((new_str = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  return (epur_strcpy(str, new_str));
}
