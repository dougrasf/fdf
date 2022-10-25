/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:00:07 by dofranci          #+#    #+#             */
/*   Updated: 2022/1fdf->zoom0/06 13:23:11 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void my_mlx_pixel_put(t_data *data, t_pixel *pixel)
{
	char	*dst;
	if((pixel->x * 4) < 0 || pixel->x * 4 > data->size_line || \
	(pixel->y * data->size_line) + (pixel->x * 4) > 1280 * 720 * 4 || \
	pixel->y * data->size_line < 0)
		return;
	dst = data->addr + (((int)pixel->y) * data->size_line + \
			((int)pixel->x) * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = pixel->color;
}

static void init_pixel(t_fdf *fdf, t_pixel *pixel, float x, float y)
{
	if (fdf->config == 1)
	{
		pixel->x1 = x + 1;
		pixel->y1 = y;
	}
	if (fdf->config == 2)
	{
		pixel->y1 = y + 1;
		pixel->x1 = x;
	}
	pixel->x = x;
	pixel->y = y;
	pixel->z = fdf->map->matriz[(int)pixel->y][(int)pixel->x];
	pixel->z1 = fdf->map->matriz[(int)pixel->y1][(int)pixel->x1];
	pixel->color = fdf->map->matrizcolor[(int)pixel->y][(int)pixel->x];
	if(fdf->color == 1)
		pixel->color = change_color(pixel->z);
	pixel->x *= fdf->zoom;
	pixel->y *= fdf->zoom;
	pixel->x1 *= fdf->zoom;
	pixel->y1 *= fdf->zoom;
	pixel->z *= fdf->z_mov;
	pixel->z1 *= fdf->z_mov;
	pixel->z *= fdf->z_mov;
	pixel->z1 *= fdf->z_mov;
	if (fdf->perspective == 1)
	{
		isometric(&pixel->x, &pixel->y, pixel->z);
		isometric(&pixel->x1, &pixel->y1, pixel->z1);
	}
	pixel->x += fdf->x_mov;
	pixel->x1 += fdf->x_mov;
	pixel->y += fdf->y_mov;
	pixel->y1 += fdf->y_mov;
}

static void	brasenham(t_fdf *fdf, float x, float y, t_data *data) 
{
	float	x_step;
	float	y_step;
	int		max;
	t_pixel *pixel;

	pixel = malloc(sizeof (t_pixel));
	init_pixel(fdf, pixel, x, y);
	x_step = pixel->x1 - pixel->x;
	y_step = pixel->y1 - pixel->y;
	max = bigger(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while(((int)(pixel->x - pixel->x1)) || ((int)(pixel->y - pixel->y1)))
	{
		//mlx_pixel_put(fdf->mlx, fdf->win, pixel.x, pixel.y, pixel.color);
		my_mlx_pixel_put(data, pixel);
		pixel->x += x_step;
		pixel->y += y_step;
	}
	free(pixel);
}

void	draw(t_fdf *fdf)
{
	int		x;
	int		y;
	t_data	*data;

	data = malloc(sizeof (t_data));
 	init_img(fdf, data);
	y = -1;
	while (++y < fdf->map->y)
	{
		x = -1;
		while (++x < fdf->map->x)
		{
			if (x < fdf->map->x - 1)
			{
				fdf->config = 1;
				brasenham(fdf, x, y, data);
			}
			if (y < fdf->map->y - 1)
			{	
				fdf->config = 2;
				brasenham(fdf, x, y, data);
			}
		}
	}
	free(data);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);

}
