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
			t_object const *objects, t_light const *light)
{
	size_t			i;
	size_t			j;
	t_ray			r;
	t_bgra			color;
	unsigned int	*img;

	i = -1;
	img = all_data->mlx_data.addr;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			r = ray_for_pixel(camera, j, i);
			color = convert_to_255(color_at(objects, light, &r));
			*img++ = color.bgra;
		}
	}
	mlx_put_image_to_window(all_data->mlx_data.mlx, all_data->mlx_data.win,
		all_data->mlx_data.img, 0, 0);
}
