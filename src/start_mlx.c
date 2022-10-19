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

void my_mlx_pixel_put(t_fdf *fdf, float x, float y, int color)
{
	char	*dst;
	if(x < 0 || x > 1920 * 1080 * 4)
		return;
	dst = fdf->data->addr + (int)(y * fdf->data->size_line + x * (fdf->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	brasenham(t_fdf *fdf, t_pixel pixel) 
{
	float	x_step;
	float	y_step;
	int		max;

	pixel.z = (fdf->map->matriz[(int)pixel.y][(int)pixel.x]);
	pixel.z1 = (fdf->map->matriz[(int)pixel.y1][(int)pixel.x1]);
	pixel.color = (fdf->map->matrizcolor[(int)pixel.y][(int)pixel.x]);

	pixel.x *= fdf->zoom;
	pixel.y *= fdf->zoom;
	pixel.x1 *= fdf->zoom;
	pixel.y1 *= fdf->zoom;
	pixel.z *= fdf->z_mov;
	pixel.z1 *= fdf->z_mov;
	// ZOOM

	pixel.x += fdf->x_mov;
	pixel.y += fdf->y_mov;
	pixel.x1 += fdf->x_mov;
	pixel.y1 += fdf->y_mov;
	//MOVIMENTO

	if(fdf->perspective == 1)
	{
		isometric(&pixel.x, &pixel.y, pixel.z, 0.8);
		isometric(&pixel.x1, &pixel.y1, pixel.z1, 0.8);
	}
	x_step = pixel.x1 - pixel.x;
	y_step = pixel.y1 - pixel.y;
	max = bigger(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	while(((int)(pixel.x - pixel.x1)) || ((int)(pixel.y - pixel.y1)))
	{
		//mlx_pixel_put(fdf->mlx, fdf->win, pixel.x, pixel.y, pixel.color);
		my_mlx_pixel_put(fdf, pixel.x, pixel.y, pixel.color);
		pixel.x += x_step;
		pixel.y += y_step;
	}
}

void	draw(t_fdf *fdf)
{
	init_img(fdf);
	fdf->map->pixel = malloc(sizeof (t_pixel));
	fdf->map->pixel->y = 0;
	while (fdf->map->pixel->y < fdf->map->y)
	{
	fdf->map->pixel->x = 0;
		while (fdf->map->pixel->x < fdf->map->x)
		{
				if (fdf->map->pixel->x < fdf->map->x - 1)
				{
					fdf->map->pixel->y1 = fdf->map->pixel->y;
					fdf->map->pixel->x1 = fdf->map->pixel->x + 1;
					brasenham(fdf, *fdf->map->pixel);
				}
				if (fdf->map->pixel->y < fdf->map->y - 1)
				{
					fdf->map->pixel->x1 = fdf->map->pixel->x;
					fdf->map->pixel->y1 = fdf->map->pixel->y + 1;
					brasenham(fdf, *fdf->map->pixel);
				}
				fdf->map->pixel->x++;
		}
		fdf->map->pixel->y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	free(fdf->map->pixel);
}

void	start_mlx(t_fdf *fdf)
{
	fdf->data = malloc(sizeof (t_data));
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
	draw(fdf);
	mlx_key_hook(fdf->win, hooks, fdf);
	mlx_expose_hook(fdf->win, expose, fdf);
	mlx_loop(fdf->mlx);
}
