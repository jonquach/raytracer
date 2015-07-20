/*
** my_getnbr_for_object.c for my_getnbr_for_object.c in /home/han_d/Dropbox/EPITECH PROJET/Raytracer
** 
** Made by han_d
** Login   <han_d@epitech.net>
** 
** Started on  Tue May 27 15:42:00 2014 han_d
** Last update Tue May 27 15:52:50 2014 han_d
*/

int	isneg(char *str)
{
  int	i;
  int	minus;

  i = 0;
  minus = 1;
  while (str[i] != '\0' && str[i] <= '0' && str[i] <= '9')
    {
      if (str[i] == '-')
	minus *= -1;
      ++i;
    }
  return (minus);
}

int	my_getnbr_for_object(char *str)
{
  int	i;
  int	nb;
  int	mult;
  int	minus;

  i = 0;
  nb = 0;
  mult = 1;
  minus = isneg(str);
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = (nb * 10) + (str[i] -
	}
      ++i;
    }
  return (minus * nb);
}
