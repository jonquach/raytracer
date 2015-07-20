/*
** set.c for set in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:12:11 2014 frayss_c
** Last update Tue Jun  3 15:55:54 2014 quach_a
*/

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include "rt.h"
#include "rtv1.h"

void	set_sphere(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -400;
  all->objects[i].z = 170;
  all->objects[i].ray = 170;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = SPHERE;
  all->objects[i].bright = 0;
}

void	set_plan(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = 0;
  all->objects[i].z = -100;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = PLAN;
  all->objects[i].bright = 0.2;
}

void	set_cone(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = -200;
  all->objects[i].z = 100;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].angle = 10 * M_PI / 180;
  all->objects[i].type = CONE;
  all->objects[i].bright = 0.7;
}

void	set_cyl(t_all *all, int i)
{
  all->objects[i].x = 400;
  all->objects[i].y = 200;
  all->objects[i].z = 0;
  all->objects[i].ray = 70;
  all->objects[i].xrot = 0;
  all->objects[i].yrot = 0;
  all->objects[i].zrot = 0;
  all->objects[i].type = CYLINDER;
  all->objects[i].bright = 0.2;
}

void	set_value(t_all *all)
{
  all->my.k_color = 0;
  /* all->color[0][0] = 0; */
  /* all->color[0][1] = 0; */
  /* all->color[0][2] = 0; */
  all->my.x_size = 1000;
  all->my.y_size = 1000;
  all->eye.x = -3000;
  all->eye.y = 0;
  all->eye.z = 500;
  all->lum.x = -400;
  all->lum.y = -200;
  all->lum.z = 1000;
  all->lum.color[0] = 255;
  all->lum.color[1] = 255;
  all->lum.color[2] = 255;
  set_sphere(all, 0);
  set_plan(all, 1);
  set_cyl(all, 3);
  //  set_cone(all, 2);
}


/* void	set_value(t_all *all) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   /\* write(1, "\n", 1); *\/ */
/*     /\* printf("%G\n", all->objects[i].bright); *\/ */
/*   /\* printf("%d\n", all->objects[i].type); *\/ */
/*   printf("\n+++++++++++++++++++++++++++\n"); */
/*   while (all->objects[i].type) */
/*     { */
/*       printf("i = %d\n", i); */
/*       printf("obj x %G\n", all->objects[i].x); */
/*       printf("obj y %G\n", all->objects[i].y); */
/*       printf("obj z %G\n", all->objects[i].z); */
/*       printf("obj ray %G\n", all->objects[i].ray); */
/*       printf("obj xrot %G\n", all->objects[i].xrot); */
/*       printf("obj yrot %G\n", all->objects[i].yrot); */
/*       printf("obj zrot %G\n", all->objects[i].zrot); */
/*       printf("obj type %d\n", all->objects[i].type); */
/*       printf("obj bright %G\n", all->objects[i].bright); */
/*       printf("obj color 0 %d\n", all->objects[i].color[0]); */
/*       printf("obj color 1 %d\n", all->objects[i].color[1]); */
/*       printf("obj color 2 %d\n", all->objects[i].color[2]); */
/*       i++; */
/*     } */
/*   printf("---------------------------------\n"); */
/*   printf("k color %d\n", all->my.k_color); */
/*   printf("x size %d\n", all->my.x_size); */
/*   printf("y size %d\n", all->my.y_size); */
/*   printf("eye x %G\n", all->eye.x); */
/*   printf("eye y %G\n", all->eye.y); */
/*   printf("eye z %G\n", all->eye.z); */
/*   printf("lum x %G\n", all->lum.x); */
/*   printf("lum y %G\n", all->lum.y); */
/*   printf("lum z %G\n", all->lum.z); */
/*   printf("lc 0 %d\n", all->lum.color[0]); */
/*   printf("lc 1 %d\n", all->lum.color[1]); */
/*   printf("lc 2 %d\n", all->lum.color[2]); */
/* } */
