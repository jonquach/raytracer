/*
** put_error.c for put_error in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Mon May 26 16:02:01 2014 quach_a
** Last update Sun Jun  8 21:51:41 2014 quach_a
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

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
