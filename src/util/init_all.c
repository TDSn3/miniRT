/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 02:43:06 by roberto          ###   ########.fr       */
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
	mwi->win_widht = WIDTH;
	mwi->win_height = HEIGHT;
	*data_key = (t_dk){0};
	all_data->mwi = mwi;
	all_data->data_img = data_img;
	all_data->data_key = data_key;
	all_data->list_object = NULL;
	mwi->mlx = mlx_init();
	mwi->win = mlx_new_window(mwi->mlx,
			mwi->win_widht, mwi->win_height, "miniRT");
}
