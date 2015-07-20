/*
** verif_nb_param.c for verif_nb_param in /home/quach_a/Dropbox/EPITECH PROJET/Raytracer/RT_MULTISPOT/src
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sun Jun  8 16:37:59 2014 quach_a
** Last update Sun Jun  8 19:48:47 2014 han_d
*/

#include <stdlib.h>
#include "lib.h"

void	bad_init(char *str)
{
  my_putstr(str);
  exit(EXIT_FAILURE);
}

void	verif_nb_param(char **tab, int param)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i++;
  if (param == 0 && i < 4)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
  else if (param == 1 && i < 4)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
  else if (param == 2 && i < 1)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
  else if (param == 3 && i < 1)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
  else if (param == 4 && i < 4)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
  else if (param == 5 && i < 4)
    bad_init("REALLY ? WHY ARE U DOING THIS ? GO ASK FOR HELP\n");
}
