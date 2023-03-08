/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created 2023/02/24 20:21:09 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 14:00:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	render(t_all_data const *all_data, t_camera const *camera,
			t_world const *world)
{
	size_t			x;
	size_t			y;
	t_ray			r;
	t_bgra			color;
	unsigned int	*img;

	x = 0;
	y = 0;
	img = (unsigned int *)all_data->data_img->addr;
	while (y < camera->vsize)
	{
		while (x < camera->hsize)
		{
			r = ray_for_pixel(camera, x, y);
			color = convert_to_255(color_at(world, r));
			*img++ = color.bgra;
			x++;
		}
		x = 0;
		y++;
	}
}
