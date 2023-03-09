/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:39:18 by roberto          ###   ########.fr       */
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
t_matrix4	*view_transform(t_tuple from, t_tuple to, t_tuple up, t_matrix4 *dst)
{
	t_tuple		forward_vector;
	t_tuple		left_vector;
	t_tuple		true_up_vector;
	t_matrix4	orientation;
	t_matrix4	translation_matrix;
	t_tuple		from_neg;
	// t_tuple		up_normalized;

	forward_vector = t_tuple_minus(&to, &from);
	normalize_vector(&forward_vector);
	// forward_vector = normalization_vector(t_tuple_minus(to, from));
	// up_normalized = normalization_vector(up);
	normalize_vector(&up);
	left_vector = cross_product_vector(&forward_vector, &up);
	true_up_vector = cross_product_vector(&left_vector, &forward_vector);
	init_matrix4_orientation(&orientation,
		forward_vector, left_vector, true_up_vector);
	// translation(t_tuple_nega(from), &translation_matrix);
	from_neg = t_tuple_nega(&from);
	translation(&from_neg, &translation_matrix);
	multiply_matrix4(&orientation, &translation_matrix, dst);
	// translation_matrix = translation(t_tuple_nega(from));
	// multiply_matrix4(&orientation, translation(t_tuple_nega(from)), dst);
	return (dst);
	// return (multiply_matrix4(orientation, translation(t_tuple_nega(from))));
}

static void	init_matrix4_orientation(
				t_matrix4 *orientation,
				t_tuple forward_vector,
				t_tuple left_vector,
				t_tuple true_up_vector)
{
	(*orientation)[0][0] = left_vector.x;
	(*orientation)[0][1] = left_vector.y;
	(*orientation)[0][2] = left_vector.z;
	(*orientation)[0][3] = 0;
	(*orientation)[1][0] = true_up_vector.x;
	(*orientation)[1][1] = true_up_vector.y;
	(*orientation)[1][2] = true_up_vector.z;
	(*orientation)[1][3] = 0;
	(*orientation)[2][0] = -forward_vector.x;
	(*orientation)[2][1] = -forward_vector.y;
	(*orientation)[2][2] = -forward_vector.z;
	(*orientation)[2][3] = 0;
	(*orientation)[3][0] = 0;
	(*orientation)[3][1] = 0;
	(*orientation)[3][2] = 0;
	(*orientation)[3][3] = 1;
}
