/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 18:04:34 by rcatini          ###   ########.fr       */
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
	{left.x, up.x, -forward.x, 0},
	{left.y, up.y, -forward.y, 0},
	{left.z, up.z, -forward.z, 0},
	{0, 0, 0, 1}
	}};
	orientation = multiply_matrix4(
	(t_matrix4){{
	{1, 0, 0, position.x},
	{0, 1, 0, -position.y},
	{0, 0, 1, position.z},
	{0, 0, 0, 1}}}, orientation);
	printf("determinant: %f\n", determinant_matrix4(orientation));
	return (orientation);
}

// t_matrix4	view_transform(t_tuple from, t_tuple to)
// {
// 	t_matrix4	orientation;

// 	to = normalization_vector(to);
// 	printf("%f %f %f\n", to.x, to.y, to.z);
// 	init_matrix4_orientation(&orientation);
// 	orientation = multiply_matrix4(
// 			orientation, translation(t_tuple_nega(from)));
// 	orientation = multiply_matrix4(orientation, rotation_x(rad_to_deg(asin(to.y))));
// 	orientation = multiply_matrix4(orientation, rotation_y(rad_to_deg(atan2(to.x, to.z))));
// 	return (orientation);
// }

// static void	init_matrix4_orientation(t_matrix4 *orientation)
// {
// 	*orientation = (t_matrix4){0};
// 	orientation->tab[0][0] = -1;
// 	orientation->tab[1][1] = 1;
// 	orientation->tab[2][2] = -1;
// 	orientation->tab[3][3] = 1;
// }
