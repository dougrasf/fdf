/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:20:00 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/18 21:42:05 by dofranci         ###   ########.fr       */
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

void	ft_free2(t_fdf *fdf)
{
	int i;
	if (!fdf->map->matrizcolor)
		return;
	i = 0;	
	while (i < fdf->map->y)
	{
		free(fdf->map->matrizcolor[i]);
		i++;
	}
	free(fdf->map->matrizcolor);
}

void close_window(t_fdf *fdf)
{
		ft_free1(fdf);
		ft_free2(fdf);
		free(fdf->data);
		free(fdf->map);
		free(fdf->mlx);
		free(fdf);
		mlx_loop_end(fdf->mlx);
		mlx_destroy_display(fdf->mlx);
		mlx_destroy_window(fdf->mlx,  fdf->win);
		exit(0);
}