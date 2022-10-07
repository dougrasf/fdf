/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:01:33 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/07 03:57:47 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;	
}

float bigger(float x, float y)
{
	if(x > y)
		return(x);
	else
		return(y);
}

float mod(float i)
{
	if(i < 0)
		return(-i);
	else
		return(i);
}
