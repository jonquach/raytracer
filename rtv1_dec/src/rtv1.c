/*
** rtv1.c for rtv1 in /home/frayss_c/rendu/MUL_2013_rtv1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sun Mar 16 18:11:13 2014 frayss_c
** Last update Sun Jun  8 21:53:48 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "../include/rt.h"
#include "../include/rtv1.h"
#include "../include/prototype.h"
#include "jpeglib.h"

int     open_jpg(char *file_name, FILE **file,
                 struct jpeg_decompress_struct *cinfo)
{
  if (access(file_name, F_OK) == -1)
    return (-1);
  if ((*file = fopen(file_name, "rb")) == NULL)
    {
      my_putstr("Fail during opening file '");
      my_putstr(file_name);
      my_putstr("'\n");
      return (-1);
    }
  jpeg_create_decompress(cinfo);
  jpeg_stdio_src(cinfo, *file);
  jpeg_read_header(cinfo, TRUE);
  return (0);
}

void    fill_data(struct jpeg_decompress_struct *cinfo,
                  t_all *all, unsigned char *image)
{
  unsigned int x;
  unsigned int y;
  int i;

  x = 0;
  i = 0;
  y = 0;
  while (x < cinfo->image_width)
    {
      y = 0;
      while (y < cinfo->image_height)
        {
          all->my.data[i + 2] =
            image[x * cinfo->image_height * 3 + y * cinfo->num_components];
          all->my.data[i + 1] =
            image[x * cinfo->image_height * 3 + y * cinfo->num_components + 1];
          all->my.data[i + 0] =
            image[x * cinfo->image_height * 3 + y * cinfo->num_components + 2];
          i += 4;
          y++;
        }
      x++;
    }
}

void    fill_mlx_struct(unsigned char *image,
                        struct jpeg_decompress_struct *cinfo,
                        t_all *all)
{
  all->my.bpp = 10;
  all->my.img_ptr = mlx_new_image(all->my.mlx_ptr, cinfo->image_width,
                                      cinfo->image_height);
  all->my.data = mlx_get_data_addr                              \
    (all->my.img_ptr, &all->my.bpp, &all->my.size_l,
     &all->my.endian);
  fill_data(cinfo, all, image);
  all->my.x_size = cinfo->image_width;
  all->my.y_size = cinfo->image_height;
}

unsigned char   *load_jpg_file(struct jpeg_decompress_struct *cinfo)
{
  unsigned char *ret;
  unsigned char *line;

  jpeg_start_decompress(cinfo);
  if ((ret = malloc(cinfo->image_width * cinfo->image_height    \
                    * sizeof(unsigned int))) == NULL)
    return (NULL);
  line = ret;
  while (cinfo->output_scanline < cinfo->output_height)
    {
      line = ret + 3 * cinfo->image_width * cinfo->output_scanline;
      jpeg_read_scanlines(cinfo, &line, 1);
    }
  jpeg_finish_decompress(cinfo);
  jpeg_destroy_decompress(cinfo);
  return (ret);
}

int     import_jpg(char *file_name, t_all *all)
{
  unsigned char *image;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE *file;

  cinfo.err = jpeg_std_error(&jerr);
  if (open_jpg(file_name, &file, &cinfo) == -1)
    return (-1);
  image = load_jpg_file(&cinfo);
  fill_mlx_struct(image, &cinfo, all);
  fclose(file);

  free(image);
  return (0);
}

void		calc(int x, int y, t_all *all)
{
  int		put;

  put = all->my.x_size * y * (all->my.bpp / 8) + x * (all->my.bpp / 8); 
  /* if (all->my.k_color == -1) */
  /*   { */
  /*     all->my.data[put] = 0; */
  /*     all->my.data[put + 1] = 0; */
  /*     all->my.data[put + 2] = 0; */
  /*   } */
  if (all->my.k_color > -1)//else
    {
      all->my.data[put] = all->objects[all->my.k_color].color_tmp[0];
      all->my.data[put + 1] = all->objects[all->my.k_color].color_tmp[1];
      all->my.data[put + 2] = all->objects[all->my.k_color].color_tmp[2];
    }
}

void		first_k(t_all *all)
{
  int		i;
  int		tmp;

  tmp = 0;
  i = 0;
  while (i < all->nb_obj)
    {
      if (all->objects[i].k < all->objects[tmp].k && all->objects[i].k > 0)
        tmp = i;
      else if ((all->objects[i].k > 0 && all->objects[tmp].k < 0) ||
	       (all->objects[i].k > 0 && i == 0))
        tmp = i;
      else if (all->objects[tmp].k < 0 && all->objects[i].k < 0)
        tmp = i;
      i++;
    }
  if (all->objects[tmp].k < 0)
    {
      all->my.k_color = -1;
    }
  else
    all->my.k_color = tmp;
}

void		all_objects(t_all *all)
{
  int		i;

  i = 0;
  while (i < all->nb_obj)
    {
      if (all->objects[i].type == SPHERE)
	inter_sphere(all, &all->objects[i]);
      if (all->objects[i].type == PLAN)
	inter_plan(all, &all->objects[i]);
      if (all->objects[i].type == CYLINDER)
	inter_cyl(all, &all->objects[i]);
      /* if (all->objects[i].type == CONE) */
      /* 	inter_cone(all, &all->objects[i]); */
      i++;
    }
  first_k(all);
}

void		pixel_by_pixel(t_all *all)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y <= all->my.y_size)
    {
      while (x <= all->my.x_size)
	{
	  all->eye.vx = 1000;
	  all->eye.vy = (all->my.x_size / 2) - x;
	  all->eye.vz = (all->my.y_size / 2) - y;
	  calc(x, y, all);
	  all_objects(all);
	  x++;
	}
      if (y <= all->my.y_size)
	{
	  y++;
	  x = 0;
	}
    }
}

int		init_raytracer(t_all *all, char *file_name)
{
  all->my.k_color = 0;
  all->my.color[0][2] = 0;
  all->my.color[0][1] = 0;
  all->my.color[0][0] = 0;
  check_error(all);
  my_putstr("hey\n");
  import_jpg(file_name, all);
  pixel_by_pixel(all);
  mlx_key_hook(all->my.win_ptr , gere_key, all);
  mlx_string_put(all->my.mlx_ptr, all->my.win_ptr, 200, 200, 0xFFFFFF, "HELLO");
  mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
                          all->my.img_ptr, 0, 0);
  //mlx_put_image_to_window(all->my.mlx_ptr, all->my.win_ptr,
  //			  all->my.img_ptr, 0, 0);
  mlx_expose_hook(all->my.win_ptr , gere_expose, all);
  mlx_loop(all->my.mlx_ptr);
  return (0);
}
