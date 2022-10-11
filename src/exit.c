/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:20:00 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/07 14:54:18 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free1(t_fdf *fdf)
{
	int i;
	if (!fdf->map->matriz)
		return;
	i = 0;	
	while (i < fdf->map->y)
	{
		free(fdf->map->matriz[i]);
		i++;
	}
	free(fdf->map->matriz);
}

void close_window(t_fdf *fdf)
{
		mlx_destroy_window(fdf->mlx,  fdf->win);
		mlx_destroy_display(fdf->mlx);
		mlx_loop_end(fdf->mlx);
		ft_free1(fdf);
		free(fdf->map);
		free(fdf->mlx);
		free(fdf);
		exit(0);
}