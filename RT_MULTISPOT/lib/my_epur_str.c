/*
** my_epur_str.c for my_epur_str.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/lib
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Sun Jun  8 19:25:04 2014 han_d
** Last update Sun Jun  8 21:45:53 2014 quach_a
*/

#include <stdlib.h>
#include "pauvray.h"
#include "lib.h"

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
