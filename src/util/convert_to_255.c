/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_255.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:21:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 22:44:09 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   x   red																  */
/*   y   green                                                                */
/*   z   blue																  */
/*   w   0                                                                    */
/*                                                                            */
/* ************************************************************************** */
t_bgra	convert_to_255(t_tuple color)
{
	t_bgra	converted_color;

	converted_color.a = 0;
	if (color.x * 255 > 255)
		converted_color.r = (unsigned char)255;
	else
		converted_color.r = color.x * 255;
	if (color.y * 255 > 255)
		converted_color.g = (unsigned char)255;
	else
		converted_color.g = color.y * 255;
	if (color.z * 255 > 255)
		converted_color.b = (unsigned char)255;
	else
		converted_color.b = color.z * 255;
	return (converted_color);
}

double	conv_color(double color_255)
{
	return (color_255 / 255);
}
