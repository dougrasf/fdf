/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:59 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/05 05:50:50 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../lib/include/libft.h"
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_pixel
{
	float x;
	float y;
	float z;
	float x1;
	float y1;
	float z1;
} t_pixel;

typedef struct s_map
{
	t_pixel *pixel;
	int fd;
	char *line;
	int **matriz;
	int x;
	int y;
} t_map;

typedef struct s_fdf
{
	t_map *map;
	void *mlx;
	void *win;
} t_fdf;

void	start_matriz(t_fdf *fdf, char *file);
void	ft_free1(t_fdf *fdf);
void	ft_free(char **split);
int		close_window(int keycode, t_fdf *fdf);
void	start_mlx(t_fdf *fdf);
void isometric(float *x, float *y, int z);

#endif