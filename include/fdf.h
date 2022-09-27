/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:17:59 by dofranci          #+#    #+#             */
/*   Updated: 2022/09/27 01:51:22 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../lib/include/libft.h"
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_map
{
	int fd;
	char *line;
	int **matriz;
	int x;
	int y;
	int color;
} t_map;

typedef struct s_fdf
{
	t_map *map;
	void *mlx;
	void *win;
} t_fdf;

void start_matriz(t_fdf *fdf, char *file);
void print_mtx(char **mtx); //func de teste //tirar dps

#endif