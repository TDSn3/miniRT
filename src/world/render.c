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

void	render(unsigned int *img_addr, t_camera const *camera,
			t_object const *objects, t_light const *light)
{
	size_t			i;
	size_t			j;
	t_ray			r;
	t_bgra			color;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			r = ray_for_pixel(camera, i, j);
			color = convert_to_255(color_at(objects, light, &r));
			*img_addr++ = color.bgra;
		}
	}
}
