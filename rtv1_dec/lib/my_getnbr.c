/*
** my_getnbr.c for my_getnbr.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer/rtv1_dec
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Thu Jun  5 18:31:34 2014 han_d
** Last update Thu Jun  5 18:31:35 2014 han_d
*/

#include <stdlib.h>
#include "../include/rt.h"
#include "../include/rtv1.h"
#include "../include/prototype.h"

int		my_getnbr(char *str)
{
  int		i;
  int		res;
  int		j;

  i = 0;
  res = 0;
  j = 1;
  if (str == NULL)
    return (0);
  while ((str[i] < '0') || (str[i] > '9' && str[i] != '\0'))
    {
      if (str[i] == '-')
	j = j * - 1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
    {
      res = ((str[i] - '0') + (res * 10));
      i++;
    }
  res = res * j;
  return (res);
}

int		go_to_nb(char *str)
{
  int		i;

  i = 0;
  while ((str[i] < '0') || (str[i] > '9' && str[i] != '\0'))
    i++;
  return (i);
}

double		my_getnbr_double(char *str)
{
  int		i;
  double	res;

  i = go_to_nb(str);
  res = 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i] && str[i] != '.')
    {
      if (str[i] == '0' && str[i + 1] == '.')
	{
	  res = ((str[i + 2] - '0') + (res * 10));
	  res = res / 10;
	  return (res);
	}
      else
	res = ((str[i] - '0') + (res * 10));
      i++;
    }
  return (res);
}
