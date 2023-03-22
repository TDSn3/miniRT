/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:47:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 20:42:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_data_and_creat_img(t_all_data *all_data);

int	gen_new_img(t_all_data *all_data)
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;

	data_img = all_data->data_img;
	mwi = all_data->mwi;
	data_img -> img = mlx_new_image(mwi -> mlx, WIDTH, HEIGHT);
	data_img -> addr = mlx_get_data_addr(
			mwi -> data_img -> img,
			&mwi -> data_img -> bits_per_pixel,
			&mwi -> data_img -> line_length,
			&mwi -> data_img -> endian);
	init_data_and_creat_img(all_data);
	mlx_put_image_to_window(mwi->mlx, mwi->win, mwi->data_img->img, 0, 0);
	mlx_destroy_image(mwi -> mlx, mwi -> data_img -> img);
	mwi -> data_img -> img = NULL;
	printf("%sNew image%s\n", COLOR_BOLD_YELLOW, COLOR_RESET);
	return (0);
}

static void	init_data_and_creat_img(t_all_data *all_data)
{
	t_world		w;
	t_camera	c;
	t_light		light;
	t_dp		data_parsing;

	init_ambiant(all_data, &data_parsing);
	init_camera(all_data, &data_parsing, &c);
	init_light(all_data, &data_parsing, &light, &w);
	if (init_object(all_data, &data_parsing))
	{
		so_clear(&all_data->list_object);
		return ;
	}
	w.lst_object = all_data->list_object;
	render(all_data, c, &w);
	so_clear(&all_data->list_object);
	all_data->list_object = NULL;
}
