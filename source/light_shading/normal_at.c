/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 13:26:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Renvois la normale sur l'objet donnée, au point donné.					  */
/*   Supposons que le point sera toujours à la surface.						  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	normal_at(t_object object, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix4	cpy;
	t_matrix4	stock;
	float		dist;

	object_point = multiply_matrix4_tuple(*inverse_matrix4(object.transform,
				&stock), world_point);
	if (object.type == SPHERE)
		object_normal = t_tuple_minus(object_point, object.position);
	else if (object.type == PLANE)
		object_normal = (t_tuple){{0, 1, 0, 0}};
	else
	{
//		dist = powf(object_point.x, 2) + powf(object_point.z, 2);
//		if (dist < 1 && object_point.y >= object.cyl_max - EPSILON)
//			object_normal = (t_tuple){{0, 1, 0, 0}};
//		else if (dist < 1 && object_point.y <= object.cyl_min + EPSILON)
//			object_normal = (t_tuple){{0, -1, 0, 0}};
//		else
			object_normal = (t_tuple){{object_point.x, 0, object_point.z, 0}};
	}
	inverse_matrix4(object.transform, &cpy);
	cpy = transpose_matrix4(cpy);
	world_normal = multiply_matrix4_tuple(cpy, object_normal);
	world_normal.w = 0;
	world_normal = normalization_vector(world_normal);
	return (world_normal);
}

