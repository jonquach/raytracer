/*
** put_error.c for put_error in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 16:02:01 2014 quach_a
** Last update Thu Jun  5 16:01:43 2014 
*/

#include <stdlib.h>
#include <string.h>
#include "../include/rt.h"

char	*put_error_char(char *str)
{
  my_putstr(str);
  return (NULL);
}

int	put_error_int(char *str)
{
  my_putstr(str);
  return (-1);
}
