/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:14:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/17 19:26:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Change la couleur d'un pixel dans une image.							  */
/*   Systèmes de coordonnées ayant pour origine le centre de la fenêtre.	  */
/*                                                                            */
/* ************************************************************************** */
void	my_mlx_pixel_put(t_all_data *all_data, int x, int y, int color)
{
	t_data_mlx_img	*data_img;
	char			*dst;

	data_img = all_data->data_img;
	dst = data_img->addr
		+ (x * data_img->line_length + y * (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
