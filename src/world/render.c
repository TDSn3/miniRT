/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bj: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created 2023/02/24 20:21:09 bj tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 14:00:56 bj tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	render(t_all_data const *all_data, t_camera const *camera,
			t_world const *world)
{
	size_t			i;
	size_t			j;
	t_ray			r;
	t_bgra			color;
	unsigned int	*img;

	i = -1;
	img = (unsigned int *)all_data->data_img->addr;
	while (++i < camera->hsize)
	{
		j = -1;
		while (++j < camera->vsize)
		{
			r = ray_for_pixel(camera, j, i);
			color = convert_to_255(color_at(world, &r));
			*img++ = color.bgra;
		}
	}
}
