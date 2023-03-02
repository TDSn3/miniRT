/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 15:26:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_all(
	t_all_data *all_data,
	t_mwi *mwi,
	t_data_mlx_img *data_img,
	t_dk *data_key)
{
	mwi->mlx = NULL;
	mwi->win = NULL;
	mwi->data_img = data_img;
	mwi->data_img->img = NULL;
	mwi->win_widht = WIDHT;
	mwi->win_height = HEIGHT;
	*data_key = (t_dk){0};
	all_data->mwi = mwi;
	all_data->data_img = data_img;
	all_data->data_key = data_key;
	all_data->gen_img = 1;
	mwi->mlx = mlx_init();
	mwi->win = mlx_new_window(mwi->mlx,
			mwi->win_widht, mwi->win_height, "miniRT");
}
