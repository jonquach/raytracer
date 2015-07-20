/*
** texture.c for texture in /home/lin_c/Dropbox/EPITECH_PROJECT/Raytracer/rtv1_dec
** 
** Made by 
** Login   <lin_c@epitech.net>
** 
** Started on  Sun Jun  8 14:50:35 2014 
** Last update Sun Jun  8 22:18:27 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "jpeglib.h"
#include "pauvray.h"
#include "lib.h"

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
