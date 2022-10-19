/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/14 03:22:39 by dofranci         ###   ########.fr       */
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
