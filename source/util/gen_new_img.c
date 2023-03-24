/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:47:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 19:22:05 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_data_and_creat_img(t_all_data *all_data);

int	gen_new_img(t_all_data *all_data)
{
	t_mwi			*mwi;

	mwi = all_data->mwi;
	init_data_and_creat_img(all_data);
	mlx_put_image_to_window(mwi->mlx, mwi->win, mwi->img, 0, 0);
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
