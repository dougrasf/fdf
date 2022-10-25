/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:39:10 by dofranci          #+#    #+#             */
/*   Updated: 2022/10/24 19:40:38 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//string hexadecimal para inteiro decimal -> "0xffffff" = 16777215
int hextodec(char *hex)
{
	unsigned int val;
	unsigned int byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++; 
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <='f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <='F')
			byte = byte - 'A' + 10;    
		val = (val << 4) | (byte & 0xF);
	}
	return(val);
}

int change_color(float z)
{
	if(z < 10)
		return(0xd2a4e9);
	else if(z < 30)
		return(0xb264da);
	else if(z < 70)
		return(0xb264d9);
	else if(z < 120)
		return(0x7a297a);
	else
		return(0x3e153e);
	return(0xffffff);
}