/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:32:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 11:10:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   d.a   xoffset															  */
/*   d.b   yoffset															  */
/*   d.c   world_x															  */
/*   d.d   world_y															  */
/*                                                                            */
/* ************************************************************************** */
t_ray	ray_for_pixel(t_camera camera, double px, double py)
{
	t_6f		d;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	t_ray		ret;

	d.a = (px + 0.5) * camera.pixel_size;
	d.b = (py + 0.5) * camera.pixel_size;
	d.c = camera.half_width - d.a;
	d.d = camera.half_height - d.b;
	pixel = multiply_matrix4_tuple(camera.inverse,
			(t_tuple){{d.d, d.c, -1, 1}});
	origin = multiply_matrix4_tuple(camera.inverse,
			(t_tuple){{0, 0, 0, 1}});
	direction = normalization_vector(t_tuple_minus(pixel, origin));
	ret.point = origin;
	ret.vector = direction;
	return (ret);
}
