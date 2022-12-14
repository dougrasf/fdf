/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:23 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/25 20:42:27 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_x(t_fdf *fdf, char **mtz)
{
	int	i;

	i = 0;
	fdf->map->line = get_next_line(fdf->map->fd);
	mtz = ft_split(fdf->map->line, ' ');
	while (mtz[i])
		i++;
	fdf->map->x = i;
	ft_free(mtz);
}

static	void	find_y(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->map->line)
	{
		i++;
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
	fdf->map->y = i;
}

static void	convert_matriz(t_fdf *fdf, char **mtz)
{
	int			i;
	static int	j;
	char		*color;

	j = 0;
	mtz = NULL;
	while (fdf->map->line)
	{
		i = -1;
		mtz = ft_split(fdf->map->line, ' ');
		while (mtz[++i])
		{
			fdf->map->matriz[j][i] = ft_atoi(mtz[i]);
			color = ft_strchr(mtz[i], ',');
			if (color != 0)
				fdf->map->matrizcolor[j][i] = hextodec(color + 3);
			else
				fdf->map->matrizcolor[j][i] = 0xffffff;
		}
		j++;
		ft_free(mtz);
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
}

void	start_matriz(t_fdf *fdf, char *file, char **mtz, int i)
{
	fdf->map = malloc(sizeof (t_map));
	fdf->map->fd = open(file, O_RDONLY);
	if (fdf->map->fd == -1 || !fdf->map)
	{
		free(fdf->map);
		exit(1);
	}
	find_x(fdf, mtz);
	find_y(fdf);
	fdf->map->matriz = (int **)malloc((fdf->map->y + 1) * sizeof(int *));
	fdf->map->matrizcolor = (int **)malloc((fdf->map->y + 1) * sizeof(int *));
	if (!fdf->map->matriz || !fdf->map->matrizcolor)
		exit(1);
	while (++i < fdf->map->y)
	{
		fdf->map->matriz[i] = (int *)malloc((fdf->map->x + 1) * sizeof(int));
		fdf->map->matrizcolor[i] = (int *)malloc((fdf->map->x + 1) * \
		sizeof(int));
		if (fdf->map->matriz[i] == NULL || fdf->map->matrizcolor[i] == NULL)
			exit(1);
	}
	fdf->map->fd = open(file, O_RDONLY);
	fdf->map->line = get_next_line(fdf->map->fd);
	convert_matriz(fdf, mtz);
	close(fdf->map->fd);
}
