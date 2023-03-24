/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:14:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 19:02:14 by rcatini          ###   ########.fr       */
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
	char			*dst;

	dst = all_data->mwi->addr
		+ (x * all_data->mwi->line_length + y
			* (all_data->mwi->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
