/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 03:05:40 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_all(t_all_data *all_data)
{
	*all_data = (t_all_data){0};
	all_data->mlx_data.mlx = mlx_init();
	all_data->mlx_data.win = mlx_new_window(all_data->mlx_data.mlx,
			WIDTH, HEIGHT, "miniRT");
	all_data->mlx_data.img = mlx_new_image(all_data->mlx_data.mlx,
			WIDTH, HEIGHT);
	all_data->mlx_data.addr = (unsigned int *)mlx_get_data_addr(
			all_data->mlx_data.img, &all_data->mlx_data.bits_per_pixel,
			&all_data->mlx_data.line_length, &all_data->mlx_data.endian);
}
