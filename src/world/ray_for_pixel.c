/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:32:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:22:47 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_ray	ray_for_pixel(t_camera const *camera, double px, double py)
{
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	// t_matrix4	cam_transform_inv;
	t_ray		ret;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	// inverse_matrix4(&camera->transform, &cam_transform_inv);
	pixel = multiply_matrix4_tuple(&camera->inverse,
			(t_tuple){{world_x, world_y, -1, 1}});
	origin = multiply_matrix4_tuple(&camera->inverse,
			(t_tuple){{0, 0, 0, 1}});
	// direction = normalization_vector(t_tuple_minus(pixel, origin));
	direction = t_tuple_minus(pixel, origin);
	normalize_vector(&direction);
	ret.point = origin;
	ret.vector = direction;
	return (ret);
}
