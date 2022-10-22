/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:57:26 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/22 02:46:49 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*	119 = w || 97 = a || 115 = s || 100 = d || 44 = , || 46 = . || 107 = k || 
	108 = l || 105 = i || 112 = p  || 99 = c || 120 = x*/
void controls(int keycode, t_fdf *fdf)
{
	if (keycode == 119)
		fdf->y_mov -= 20;
	if (keycode == 97)
		fdf->x_mov -= 20;
	if (keycode == 115)
		fdf->y_mov += 20;
	if (keycode == 100)
		fdf->x_mov += 20;
	if (keycode == 107)
		fdf->z_mov -= 1;
	if (keycode == 108)
		fdf->z_mov += 1;
	if (keycode == 107)
		fdf->z_mov -= 1;
	if (keycode == 108)
		fdf->z_mov += 1;
	if (keycode == 105)
		fdf->perspective = 1;
	if (keycode == 112)
		fdf->perspective = 0;
	if (keycode == 99)
		fdf->color = 1;
	if(keycode == 44)
			fdf->zoom -= 1;
	if(keycode == 46)
			fdf->zoom += 1;
	if(keycode == 99)
		fdf->color = 1;
	if(keycode == 120)
		fdf->color = 0;
}

int hooks(int keycode, t_fdf *fdf)
{
	ft_printf("%i\n", keycode);
	controls(keycode, fdf);
	if(keycode == 65307 || keycode == 113)
	{	
		close_window(fdf);
		return(0);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	return(0);
}

int expose(t_fdf *fdf)
{
	draw(fdf);
	return(0);
}