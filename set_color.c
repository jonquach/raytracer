/*
** set_color.c for set_color in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:13:18 2014 frayss_c
** Last update Mon May 26 14:24:37 2014 frayss_c
*/

#include "rtv1.h"

void	set_color(t_all *all)
{
  all->my.color[0][2] = 0;
  all->my.color[0][1] = 0;
  all->my.color[0][0] = 0;
  all->objects[0].color[2] = 255;
  all->objects[0].color[1] = 255;
  all->objects[0].color[0] = 255;
  all->objects[1].color[2] = 25;
  all->objects[1].color[1] = 150;
  all->objects[1].color[0] = 25;
  all->objects[2].color[2] = 0;
  all->objects[2].color[1] = 0;
  all->objects[2].color[0] = 255;
  all->objects[3].color[2] = 255;
  all->objects[3].color[1] = 0;
  all->objects[3].color[0] = 0;
  all->objects[4].color[2] = 154;
  all->objects[4].color[1] = 20;
  all->objects[4].color[0] = 200;
}

/* void	set_color(t_all *all) */
/* { */
/*   all->my.color[0][2] = 0; */
/*   all->my.color[0][1] = 0; */
/*   all->my.color[0][0] = 0; */
/*   all->my.color[1][2] = 255; */
/*   all->my.color[1][1] = 255; */
/*   all->my.color[1][0] = 255; */
/*   all->my.color[2][2] = 25; */
/*   all->my.color[2][1] = 150; */
/*   all->my.color[2][0] = 25; */
/*   all->my.color[3][2] = 0; */
/*   all->my.color[3][1] = 0; */
/*   all->my.color[3][0] = 255; */
/*   all->my.color[4][2] = 255; */
/*   all->my.color[4][1] = 0; */
/*   all->my.color[4][0] = 0; */
/* } */
