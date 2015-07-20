/*
** functions.c for functions in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:34 2014 frayss_c
** Last update Fri Jun  6 21:36:28 2014 han_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "rtv1.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
