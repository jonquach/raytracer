/*
** my_getnbr.c for getnbr in /home/kauch_j/rendu/Bistro
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Wed Nov  6 16:15:23 2013 kauch_j
** Last update Tue May 27 19:25:11 2014 quach_a
*/

#include <stdlib.h>

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	j;

  i = 0;
  res = 0;
  j = 1;
  if (str == NULL)
    return (0);
  while (str[i] < '0' || str[i] > '9' && str[i] != '\0')
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
  while (str[i] < '0' || str[i] > '9' && str[i] != '\0')
    i++;
  return (i);
}

double		my_getnbr_double(char *str)
{
  int		i;
  int		j;
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
