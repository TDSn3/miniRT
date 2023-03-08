/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:14:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:57:26 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Change la couleur d'un pixel dans une image.							  */
/*   Systèmes de coordonnées ayant pour origine le centre de la fenêtre.	  */
/*                                                                            */
/* ************************************************************************** */
void	my_mlx_pixel_put(t_all_data const *all_data, int x, int y, int color)
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;
	char			*dst;
	int				s_x;
	int				s_y;

	data_img = all_data->data_img;
	mwi = all_data->mwi;
	if (x < (mwi->win_widht * -1) / 2
		|| x > mwi->win_widht / 2
		|| y < (mwi->win_height * -1) / 2
		|| y > mwi->win_height / 2)
		return ;
	s_x = mwi->win_widht / 2 + x;
	s_y = mwi->win_height / 2 - y;
	dst = data_img->addr
		+ (s_y * data_img->line_length + s_x * (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
