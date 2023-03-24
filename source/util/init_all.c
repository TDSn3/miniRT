/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 19:00:34 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	init_scene(t_all_data *all_data);

int	init_all(
	t_all_data *all_data,
	t_mwi *mwi,
	t_dk *data_key)
{
	mwi->win_height = HEIGHT;
	mwi->win_widht = WIDTH;
	mwi->mlx = mlx_init();
	if (mwi->mlx == NULL)
		return (1);
	mwi->win = mlx_new_window(mwi->mlx, WIDTH, HEIGHT, "miniRT");
	if (mwi->win == NULL)
		return (mlx_destroy_display(mwi->mlx), free(mwi->mlx), 1);
	mwi->img = mlx_new_image(mwi->mlx, WIDTH, HEIGHT);
	if (mwi->img == NULL)
		return (mlx_destroy_window(mwi->mlx, mwi->win),
			mlx_destroy_display(mwi->mlx), free(mwi->mlx), 1);
	mwi->addr = mlx_get_data_addr(mwi->img,
			&mwi->bits_per_pixel, &mwi->line_length,
			&mwi->endian);
	if (mwi->addr == NULL)
		return (mlx_destroy_image(mwi->mlx, mwi->img),
			mlx_destroy_window(mwi->mlx, mwi->win),
			mlx_destroy_display(mwi->mlx), free(mwi->mlx), 1);
	*data_key = (t_dk){0};
	*all_data = (t_all_data){.mwi = mwi,
		.data_key = data_key, .parsed_scene = all_data->parsed_scene};
	return (0);
}
