/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:42:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/01 10:15:43 by tda-silv         ###   ########.fr       */
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
t_camera	give_camera(double hsize, double vsize, double field_of_view)
{
	t_camera	ret;
	double		half_view;
	double		aspect;

	ret.hsize = hsize;
	ret.vsize = vsize;
	ret.field_of_view = field_of_view;
	ret.transform = give_identity_matrix4();
	half_view = tanf(field_of_view / 2);
	aspect = hsize / vsize;
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
	ret.pixel_size = (ret.half_width * 2) / ret.hsize;
	return (ret);
}
