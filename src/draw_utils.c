/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:01:33 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/25 20:10:01 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

float	bigger(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	init_img(t_fdf *fdf, t_data *data)
{
	fdf->img = mlx_new_image(fdf->mlx, 1280, 720);
	data->addr = mlx_get_data_addr(fdf->img, &data->bits_per_pixel, \
	&data->size_line, &data->endian);
}

void	init_data(t_fdf *fdf, t_pixel *pixel, float x, float y)
{
	pixel->x = x;
	pixel->y = y;
	pixel->z = fdf->map->matriz[(int)pixel->y][(int)pixel->x];
	pixel->z1 = fdf->map->matriz[(int)pixel->y1][(int)pixel->x1];
	pixel->color = fdf->map->matrizcolor[(int)pixel->y][(int)pixel->x];
	if (fdf->color == 1)
		pixel->color = change_color(pixel->z);
	pixel->x *= fdf->zoom;
	pixel->y *= fdf->zoom;
	pixel->x1 *= fdf->zoom;
	pixel->y1 *= fdf->zoom;
	pixel->z *= fdf->z_mov;
	pixel->z1 *= fdf->z_mov;
	pixel->z *= fdf->z_mov;
	pixel->z1 *= fdf->z_mov;
}
