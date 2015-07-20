f/*
** my_putnbr.c for my_putnbr.c in /home/frayss_c/rendu/colle3_frayss_c_OaHTo
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Mon May 12 20:55:39 2014 frayss_c
** Last update Tue May 27 16:42:59 2014 kauch_j
*/

#include "my_reader.h"

void		my_putnbr(int nb)
{
  int		div;

  div = 1;
  while (nb / div > 9)
    div = div * 10;
  while (div > 0)
    {
      my_putchar((nb / div) % 10 + 48);
      div = div / 10;
    }
}
