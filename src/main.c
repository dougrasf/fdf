/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/11 13:38:42 by dofranci         ###   ########.fr       */
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

static	void start_fdf(t_fdf *fdf, char *file)
{
	start_matriz(fdf, file);
	start_mlx(fdf);
	return;
}

int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	fdf = NULL;
	fdf = malloc(sizeof (t_fdf));
	if(argc != 2)
	{
		ft_printf("Arguments Error (two arguments)\n");
		return(1);
	}
	if(validation_argv(argv[1]) == 1)
	{
		ft_printf("File extension Error (.fdf)\n");
		return(2);
	}
	start_fdf(fdf, argv[1]);
	free(fdf);
	return(0);
}
