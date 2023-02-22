/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 11:05:32 by tda-silv         ###   ########.fr       */
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
	t_matrix	*cpy;

	object_point = multiply_matrix_tuple(inverse_matrix(sphere.transform),
			&world_point);
	object_normal = t_tuple_minus(object_point, sphere.position);
	cpy = inverse_matrix(sphere.transform);
	transposing_matrix(cpy);
	world_normal = multiply_matrix_tuple(cpy, &object_normal);
	world_normal.w = 0;
	world_normal = normalization_vector(world_normal);
	free(cpy);
	return (world_normal);
}
