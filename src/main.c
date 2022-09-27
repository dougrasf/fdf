/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:39:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/09/27 01:19:52 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_mtx(char **mtx) //func de teste //tirar dps
{
    int i = 0;
    while (mtx[i++])
        ft_printf("%s\n", mtx[i]);
}

static int validations(int argc, char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if(argc != 2 || len == 0)
	{
		ft_printf("Arguments Error\n");
		return(1);
	}
	else if(!ft_strnstr(argv[1], ".fdf", len))
	{
		ft_printf("File extension Error\n");
		return(1);
	}
	return(0);
}

void start_fdf(t_fdf *fdf, char *file)
{
	start_matriz(fdf, file);
	//start_mlx();
	return;
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;

	fdf = NULL;
	fdf = malloc(sizeof (t_fdf));
	if(validations(argc, argv) == 1)
		return(1);
	start_fdf(fdf, argv[1]);
	free(fdf);
	return(0);
}
