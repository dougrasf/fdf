/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/24 21:53:24 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int validation_argv(char *argv)
{
	int count;

	count = ft_strlen(argv);
	count -= 4;
	if(ft_strncmp(".fdf", argv + count, 4))
		return(1);
	return(0);
}

int predefinitions(t_fdf *fdf, int pref)
{
	if(pref == 0)
	{
		if(fdf->map->x < 20 && fdf->map->y < 20)
			return(20);
		if(fdf->map->x < 40 && fdf->map->y < 40)
			return(15);
		if(fdf->map->x < 60 && fdf->map->y < 60)
			return(10);
		if(fdf->map->x < 110 && fdf->map->y < 110)
			return(5);
		if(fdf->map->x < 250 && fdf->map->y < 250)
			return(3);
		if(fdf->map->x > 300 && fdf->map->y > 300)
			return(2);
	}
	else if(pref == 1)
	{
		if(fdf->map->y > 200)
			return(50);
		else
			return(190);
	}
	return(5);
}

void	start_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if(fdf->mlx == NULL)
		return;
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FDF");
	if(fdf->win == NULL)
		return;
	fdf->zoom = predefinitions(fdf, 0);
	fdf->x_mov = 360;
	fdf->y_mov = predefinitions(fdf, 1);
	fdf->z_mov = 1;
	fdf->perspective = 1;
	fdf->color = 0;
	draw(fdf);
	mlx_key_hook(fdf->win, hooks, fdf);
	mlx_expose_hook(fdf->win, expose, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	fdf = NULL;
	fdf = malloc(sizeof (t_fdf));
	if(!fdf)
		return(1);
	if(argc != 2)
	{
		ft_printf("Arguments Error (two arguments)\n");
		free(fdf);
		return(1);
	}
	if(validation_argv(argv[1]) == 1)
	{
		ft_printf("File extension Error (.fdf)\n");
		free(fdf);
		return(2);
	}
	start_matriz(fdf, argv[1]);
	start_mlx(fdf);
	free(fdf);
	return(0);
}
