/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 16:27:50 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

// static void	init_matrix4_orientation(t_matrix4 *orientation);

/* ************************************************************************** */
/*                                                                            */
/*   from   position de la camera											  */
/*   to     direction de la camera											  */
/*   up     direction vers le haut de la camera								  */
/*                                                                            */
/* ************************************************************************** */
t_matrix4	view_transform(t_tuple position, t_tuple forward)
{
	t_matrix4	orientation;
	t_tuple		up;
	t_tuple		left;

	forward = normalization_vector(forward);
	if (forward.x == 0 && forward.z == 0)
		up = (t_tuple){{0, 0, -1, 0}};
	else
		up = (t_tuple){{0, 1, 0, 0}};
	left = cross_product_vector(forward, up);
	up = cross_product_vector(left, forward);
	orientation = (t_matrix4){{
	{left.x, left.y, left.z, 0},
	{up.x, up.y, up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}}};
	orientation = multiply_matrix4(orientation,
			(t_matrix4){{
		{1, 0, 0, -position.x},
		{0, 1, 0, -position.y},
		{0, 0, 1, -position.z},
		{0, 0, 0, 1}}});
	return (orientation);
}
