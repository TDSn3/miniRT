/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:42:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 06:10:03 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   field_of_view   Angle qui décrit ce que la caméra peut voir.			  */
/*                                                                            */
/*   Lorsque le champ de vision est petit, la vue sera zoomée,				  */
/*   agrandissant une zone plus petite de la scène.							  */
/*                                                                            */
/* ************************************************************************** */
t_camera	give_camera(double field_of_view)
{
	t_camera	ret;
	double		half_view;
	double		aspect;

	ret = (t_camera){0};
	ret.field_of_view = field_of_view;
	identity_matrix(4, (double *)&ret.transform);
	inverse_matrix4(&ret.transform, &ret.inverse);
	half_view = tanf(field_of_view / 2);
	aspect = WIDTH / HEIGHT;
	if (aspect >= 1)
	{
		ret.half_width = half_view;
		ret.half_height = half_view / aspect;
	}
	else
	{
		ret.half_width = half_view * aspect;
		ret.half_height = half_view;
	}
	ret.pixel_size = (ret.half_width * 2) / WIDTH;
	return (ret);
}
