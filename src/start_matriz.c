/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:23 by dofranci          #+#    #+#             */
/*   Updated: 2022/09/27 16:33:07 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free(char **split)
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

static void	ft_free1(t_fdf *fdf)
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

static void find_x(t_fdf *fdf, char **mtz)
{
	int i;

	i = 0;
	fdf->map->line = get_next_line(fdf->map->fd);
	mtz = ft_split(fdf->map->line, ' ');
	while(mtz[i])
		i++;
	fdf->map->x = i;
	ft_free(mtz);
}

static void find_y(t_fdf *fdf)
{
	int i;
	
	i = 0;
	while(fdf->map->line)
	{
		i++;
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
	fdf->map->y = i;
}

static void convert_matriz(t_fdf *fdf, char **mtz, char *file)
{
	int i;
	int j;

	j = 0;
	mtz = NULL;
	fdf->map->fd = open(file, O_RDONLY);
	fdf->map->line = get_next_line(fdf->map->fd);
	//ft_printf("%s", fdf->map->line);
	while(fdf->map->line)
	{
		i = -1;
		mtz = ft_split(fdf->map->line, ' ');
			while(mtz[++i])
					fdf->map->matriz[j][i] = ft_atoi(mtz[i]);
		j++;
		ft_free(mtz);
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
	close(fdf->map->fd);
}

void start_matriz(t_fdf *fdf, char *file)
{
	int		i;
	int		j;
	char	**mtz;

	mtz = NULL;
	fdf->map = malloc(sizeof (t_map));
	fdf->map->fd = open(file, O_RDONLY);
	j = 0;
	find_x(fdf, mtz);
	// pega quantos elementos tem em x
	find_y(fdf);
	// pega quantos elementos tem em y
	fdf->map->matriz = (int **)malloc((fdf->map->y + 1) * sizeof(int *));
	i = -1;
	while(++i < fdf->map->y)
		fdf->map->matriz[i] = (int *)malloc((fdf->map->x + 1) * sizeof(int));
	// aloca espaço para a matriz baseado no numero de elementos x e y
	convert_matriz(fdf, mtz, file);
	// i = -1;
	// j = 0;
	// while(fdf->map->matriz[++i])
	// 	ft_printf("%i", fdf->map->matriz[i][0]);
	// converte a matriz de char obtida ao ler o mapa para uma matriz de int 
	ft_free1(fdf);
	free(fdf->map);
}
