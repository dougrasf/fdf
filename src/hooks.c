/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:57:26 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/11 13:35:38 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// 119 = w || 97 = a || 115 = s || 100 = d || 44 = , || 46 = .
void controls(int keycode, t_fdf *fdf)
{
	if (keycode == 119)
		fdf->y_mov -= 10;
	if (keycode == 97)
		fdf->x_mov -= 10;
	if (keycode == 115)
		fdf->y_mov += 10;
	if (keycode == 100)
		fdf->x_mov += 10;
	if(keycode == 44)
			fdf->zoom -= 2;
	if(keycode == 46)
			fdf->zoom += 2;
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