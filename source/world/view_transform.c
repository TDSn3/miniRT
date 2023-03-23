/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/23 19:46:20 by rcatini          ###   ########.fr       */
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
	up = (t_tuple){{0, 1, 0, 0}};
	left = cross_product_vector(forward, up);
	up = cross_product_vector(left, forward);
	up = normalization_vector(up);
	left = normalization_vector(left);
	orientation = (t_matrix4){{
	{left.x, up.x, -forward.x, position.x},
	{left.y, up.y, -forward.y, position.y},
	{left.z, up.z, -forward.z, position.z},
	{0, 0, 0, 1}
	}};
	return (orientation);
}

// static void	init_matrix4_orientation(t_matrix4 *orientation)
// {
// 	*orientation = (t_matrix4){0};
// 	orientation->tab[0][0] = -1;
// 	orientation->tab[1][1] = 1;
// 	orientation->tab[2][2] = -1;
// 	orientation->tab[3][3] = 1;
// }
