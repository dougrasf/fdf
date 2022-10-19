/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:59 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/20 01:16:48 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../lib/include/libft.h"
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;

} t_data;

typedef struct s_pixel
{
	float x;
	float x1;
	float y;
	float y1;
	int z;
	int z1;
	int color;
} t_pixel;

typedef struct s_map
{
	t_pixel *pixel;
	int fd;
	char *line;
	int **matriz;
	int **matrizcolor;
	int x;
	int y;
} t_map;

typedef struct s_fdf
{
	t_map *map;
	t_data *data;
	void *mlx;
	void *win;
	int zoom;
	int x_mov;
	int y_mov;
	int z_mov;
	int perspective;
	int color;
} t_fdf;

void	start_matriz(t_fdf *fdf, char *file);
void	ft_free1(t_fdf *fdf);
void	ft_free2(t_fdf *fdf);
void	ft_free(char **split);
void	start_mlx(t_fdf *fdf);
void	isometric(float *x, float *y, int z, double angle);
void	draw(t_fdf *fdf);
void	close_window(t_fdf *fdf);
float	bigger(float x, float y);
float	mod(float i);
int		hooks(int keycode, t_fdf *fdf);
int		expose(t_fdf *fdf);
void	init_img(t_fdf *fdf);
int		hextodec(char *hex);


#endif
