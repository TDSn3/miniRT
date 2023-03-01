/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:21:09 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/01 15:08:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	render(t_all_data *all_data, t_camera camera, t_world *world)
{
	t_ray	r;
	t_tuple	color;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < camera.vsize - 1)
	{
		while (x < camera.hsize - 1)
		{
			r = ray_for_pixel(camera, x, y);
			color = color_at(world, r);
//			if ((y == 0 && x == 0)|| (y == camera.vsize - 2 && x == 0))
//				printf("(%f,%f,%f)\n", r.vector.x, r.vector.y, r.vector.z);
			my_mlx_pixel_put(all_data, x - camera.hsize / 2, y - camera.vsize / 2, convert_to_255(color).bgra);
			x++;
		}
//		if (y == 0 || y == camera.vsize - 2)
//			printf("(%f,%f,%f)\n", r.vector.x, r.vector.y, r.vector.z);
		x = 0;
		y++;
	}
}
