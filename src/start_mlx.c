/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:00:07 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/05 06:11:31 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float bigger(float x, float y)
{
	if(x > y)
		return(x);
	else
		return(y);
}

float mod(float i)
{
	if(i < 0)
		return(-i);
	else
		return(i);
}

void brasenham(t_fdf *fdf, t_pixel pixel) 
{
	float x_step;
	float y_step;
	
	// ZOOM
	pixel.x *= 30;
    pixel.y *= 30; 
    pixel.x1 *= 30;
    pixel.y1*= 30;
	pixel.x += 10;
    pixel.y += 10;
    pixel.x1 += 10;
    pixel.y1 += 10;

	
	pixel.z = fdf->map->matriz[(int)pixel.y][(int)pixel.x];
	//pixel.z1 = fdf->map->matriz[(int)pixel.y1][(int)pixel.x1];
	//isometric(&pixel.x, &pixel.y, pixel.z);
	//isometric(&pixel.x1, &pixel.y1, pixel.z1);
	// 3D

	x_step = pixel.x1 - pixel.x;
	y_step = pixel.y1 - pixel.y;
	// step = diferença entre os pontos (final e inicial), quanto percorrer
	// x_step = 9 e y_step = 18
	
	x_step /= bigger(mod(x_step), (mod(y_step))); // 0.5
	y_step /= bigger(mod(x_step), (mod(y_step))); // 1
	//descobre quanto cada elemento deve percorrer
	//
	
	while((int)(pixel.x - pixel.x1) || (int)(pixel.y - pixel.y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, pixel.x, pixel.y, 0xffffff);
		pixel.x += x_step;
		pixel.y += y_step;
	}
}

void draw(t_fdf *fdf)
{
	fdf->map->pixel = malloc(sizeof (t_pixel));
	fdf->map->pixel->y = 0;
	fdf->map->pixel->x1 = 1;
	fdf->map->pixel->y1 = 0;
	while(fdf->map->pixel->y < fdf->map->y)
	{
		fdf->map->pixel->x = 0;
		while(fdf->map->pixel->x < fdf->map->x)
		{
			fdf->map->pixel->y1 = fdf->map->pixel->y;
			brasenham(fdf, *fdf->map->pixel);
			fdf->map->pixel->x1 = fdf->map->pixel->x;
			fdf->map->pixel->y1 += 1;
			if(fdf->map->pixel->y < fdf->map->y - 1)
			{
				brasenham(fdf, *fdf->map->pixel);
				fdf->map->pixel->y1 = fdf->map->pixel->y;
			}
			fdf->map->pixel->x++;
		}
		fdf->map->pixel->y++;
	}
	free(fdf->map->pixel);
}

void start_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if(fdf->mlx == NULL)
		return;
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FDF");
	if(fdf->win == NULL)
		return;
	draw(fdf);
	mlx_key_hook(fdf->win, close_window, fdf);
	mlx_loop(fdf->mlx);
}
