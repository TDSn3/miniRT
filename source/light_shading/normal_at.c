/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 23:31:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Renvois la normale sur la sphère donnée, au point donné.				  */
/*   Supposons que le point sera toujours à la surface de la sphère.		  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	normal_at(t_object sphere, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix4	cpy;
	t_matrix4	stock;

	object_point = multiply_matrix4_tuple(*inverse_matrix4(sphere.transform,
				&stock), world_point);
	object_normal = t_tuple_minus(object_point, sphere.position);
	inverse_matrix4(sphere.transform, &cpy);
	cpy = transpose_matrix4(cpy);
	world_normal = multiply_matrix4_tuple(cpy, object_normal);
	world_normal.w = 0;
	world_normal = normalization_vector(world_normal);
	return (world_normal);
}
