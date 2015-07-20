/*
** my_strncmp.c for my_strncmp.c in /home/frayss_c/rendu/colle3_frayss_c_OaHTo
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Mon May 12 20:38:22 2014 frayss_c
** Last update Mon May 12 21:25:03 2014 frayss_c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_reader.h"

int	my_strncmp(int i, char *str, char *str_comp)
{
  int	j;

  j = 0;
  while (str[i] == str_comp[j] && str_comp[j] != '\0' && str[i] != '\0')
    {
      i++;
      j++;
    }
  if (str_comp[j] == '\0')
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
