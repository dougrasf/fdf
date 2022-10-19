/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:01:33 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/20 01:16:37 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

// void	isometric(t_pixel *pixel)
// {
// 	pixel->x = (pixel->x - pixel->y) * cos(0.8);
// 	pixel->y = (pixel->x + pixel->y) * sin(0.8) - pixel->z;
// 	pixel->x1 = (pixel->x1 - pixel->y1) * cos(0.8);
// 	pixel->y1 = (pixel->x1 + pixel->y1) * sin(0.8) - pixel->z1;
// }

void	isometric(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

float	bigger(float x, float y)
{
	if(x > y)
		return(x);
	else
		return(y);
}

float	mod(float i)
{
	if(i < 0)
		return(-i);
	else
		return(i);
}

void init_img(t_fdf *fdf)
{
	fdf->data->img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel, &fdf->data->size_line, &fdf->data->endian);
}

//string hexadecimal para inteiro decimal -> "0xffffff" = 16777215
int hextodec(char *hex)
{
	unsigned int val;
	unsigned int byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++; 
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <='f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <='F')
			byte = byte - 'A' + 10;    
		val = (val << 4) | (byte & 0xF);
	}
	return(val);
}

/*
B = 11
C = 12
D = 13
E = 14
F = 15
*/
