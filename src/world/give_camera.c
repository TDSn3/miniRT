/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:42:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 05:58:15 by roberto          ###   ########.fr       */
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
t_camera	give_camera(float hsize, float vsize, float field_of_view)
{
	t_camera	ret;
	float		half_view;
	float		aspect;

	ret.hsize = hsize;
	ret.vsize = vsize;
	ret.field_of_view = field_of_view;
	ret.transform = give_identity_matrix4();
	ret.inverse = give_identity_matrix4();
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
