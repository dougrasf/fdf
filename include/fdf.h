/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:59 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/25 21:01:00 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/include/libft.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	config;
	float	z_scale;
}	t_data;

typedef struct s_pixel
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
	int		color;
}	t_pixel;

typedef struct s_map
{
	t_pixel	*pixel;
	int		fd;
	char	*line;
	int		**matriz;
	int		**matrizcolor;
	int		x;
	int		y;
	int		map_scale;
}	t_map;

typedef struct s_fdf
{
	t_map	*map;
	t_data	*data;
	void	*mlx;
	void	*win;
	void	*img;
	int		zoom;
	int		x_mov;
	int		y_mov;
	float	z_mov;
	int		perspective;
	int		color;
	int		config;
	char	*buffer;
}	t_fdf;

void	start_matriz(t_fdf *fdf, char *file, char **mtz, int i);
void	ft_free1(t_fdf *fdf);
void	ft_free(char **split);
void	start_mlx(t_fdf *fdf);
void	isometric(float *x, float *y, int z);
int		close_window(t_fdf *fdf);
float	bigger(float x, float y);
float	mod(float i);
int		hooks(int keycode, t_fdf *fdf);
int		expose(t_fdf *fdf);
void	init_img(t_fdf *fdf, t_data *data);
int		hextodec(char *hex);
int		change_color(float z);
void	draw(t_fdf *fdf, int x, int y);
void	init_data(t_fdf *fdf, t_pixel *pixel, float x, float y);

#endif
