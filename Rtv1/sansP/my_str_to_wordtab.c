/*
** my_str_to_wordtab.c for  in /home/kauch_j/Dropbox/EPITECH PROJET/Raytracer
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Mon May 26 17:03:12 2014 kauch_j
** Last update Sat May 31 18:12:35 2014 quach_a
*/

#include <stdlib.h>
#include "rt.h"
#include "rtv1.h"

int	find_char(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
        return (0);
      ++i;
    }
  return (1);
}

int	nb_word(char *str, char *sep)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (find_char(str[i], sep) == 1)
	{
	  ++nb;
	  while (str[i] != '\0' && find_char(str[i], sep) == 1)
	    ++i;
	}
      else
	++i;
    }
  return (nb);
}

char	*wordcpy(char *str, char *sep, int i)
{
  char	*word;
  int	j;

  j = i;
  while (find_char(str[j], sep) == 1 && str[j] != '\0')
    j++;
  if ((word = malloc(sizeof(char) * j - i + 1)) == NULL)
    return (NULL);
  j = 0;
  while (find_char(str[i], sep) == 1 && str[i] != '\0')
    word[j++] = str[i++];
  word[j] = '\0';
  word = epur_str(word);
  return (word);
}

char	**my_str_to_wordtab(char *str, char *sep)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * nb_word(str, sep) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      if (find_char(str[i], sep) == 1)
        {
          tab[j++] = wordcpy(str, sep, i);
          while (find_char(str[i], sep) == 1 && str[i] != '\0')
            ++i;
        }
      else
        ++i;
    }
  tab[j] = NULL;
  return (tab);
}
