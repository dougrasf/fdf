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

void my_mlx_pixel_put(t_data *data, t_pixel *pixel)
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

int find_color(float z)
{
	if(z < 10)
		return(0x3e153e);
	else if(z < 30)
		return(0x7a297a);
	else if(z < 70)
		return(0xb264d9);
	else if(z < 120)
		return(0xb264da);
	else
		return(0xd2a4e9);
	return(0xffffff);
}

void init_pixel(t_fdf *fdf, t_pixel *pixel, float x, float y)
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
		pixel->color = find_color(pixel->z);
	pixel->x *= fdf->zoom;
	pixel->y *= fdf->zoom;
	pixel->x1 *= fdf->zoom;
	pixel->y1 *= fdf->zoom;
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

void	brasenham(t_fdf *fdf, float x, float y, t_data *data) 
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
// void	draw(t_fdf *fdf)
// {
// 	init_img(fdf);
// 	int x;
// 	int y;
// 	fdf->map->pixel = malloc(sizeof (t_pixel));
// 	fdf->map->pixel->y = 0;
// 	y = 0;
// 	while (fdf->map->pixel->y < fdf->map->y)
// 	{
// 	fdf->map->pixel->x = 0;
// 		while (fdf->map->pixel->x < fdf->map->x)
// 		{
// 				if (fdf->map->pixel->x < fdf->map->x - 1)
// 				{
// 					fdf->map->pixel->y1 = fdf->map->pixel->y;
// 					fdf->map->pixel->x1 = fdf->map->pixel->x + 1;
// 					brasenham(fdf, *fdf->map->pixel);
// 				}
// 				if (fdf->map->pixel->y < fdf->map->y - 1)
// 				{
// 					fdf->map->pixel->x1 = fdf->map->pixel->x;
// 					fdf->map->pixel->y1 = fdf->map->pixel->y + 1;
// 					brasenham(fdf, *fdf->map->pixel);
// 				}
// 				fdf->map->pixel->x++;
// 		}
// 		fdf->map->pixel->y++;
// 	}
// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
// 	free(fdf->map->pixel);
// }

void	start_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if(fdf->mlx == NULL)
		return;
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FDF");
	if(fdf->win == NULL)
		return;
	fdf->zoom = 10;
	fdf->x_mov = 100;
	fdf->y_mov = 100;
	fdf->z_mov = 1;
	fdf->perspective = 1;
	fdf->color = 0;
	draw(fdf);
	mlx_key_hook(fdf->win, hooks, fdf);
	mlx_expose_hook(fdf->win, expose, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
}
