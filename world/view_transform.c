/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/01 11:42:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_matrix4_orientation(
				t_matrix4 *orientation,
				t_tuple forward_vector,
				t_tuple left_vector,
				t_tuple true_up_vector);

/* ************************************************************************** */
/*                                                                            */
/*   from   position de la camera											  */
/*   to     direction de la camera											  */
/*   up     direction vers le haut de la camera								  */
/*                                                                            */
/* ************************************************************************** */
t_matrix4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward_vector;
	t_tuple		left_vector;
	t_tuple		true_up_vector;
	t_matrix4	orientation;

	forward_vector = normalization_vector(t_tuple_minus(to, from));
	left_vector = cross_product_vector(forward_vector,
			normalization_vector(up));
	true_up_vector = cross_product_vector(left_vector, forward_vector);
	init_matrix4_orientation(&orientation,
		forward_vector, left_vector, true_up_vector);
	return (multiply_matrix4(orientation, translation(t_tuple_nega(from))));
}

static void	init_matrix4_orientation(
				t_matrix4 *orientation,
				t_tuple forward_vector,
				t_tuple left_vector,
				t_tuple true_up_vector)
{
	orientation->tab[0][0] = left_vector.x;
	orientation->tab[0][1] = left_vector.y;
	orientation->tab[0][2] = left_vector.z;
	orientation->tab[0][3] = 0;
	orientation->tab[1][0] = true_up_vector.x;
	orientation->tab[1][1] = true_up_vector.y;
	orientation->tab[1][2] = true_up_vector.z;
	orientation->tab[1][3] = 0;
	orientation->tab[2][0] = -forward_vector.x;
	orientation->tab[2][1] = -forward_vector.y;
	orientation->tab[2][2] = -forward_vector.z;
	orientation->tab[2][3] = 0;
	orientation->tab[3][0] = 0;
	orientation->tab[3][1] = 0;
	orientation->tab[3][2] = 0;
	orientation->tab[3][3] = 1;
}
