/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:32:12 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static t_tuple	return_world_normal(t_matrix4 const *cpy, t_tuple object_normal);

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
	t_matrix4	cpy;
	// t_matrix4	stock;
	t_matrix4	transposed;
	double		dist;

	object_point = multiply_matrix4_tuple(&object.inverse, world_point);
	if (object.type == SPHERE)
		object_normal = t_tuple_minus(&object_point, &object.position);
	else if (object.type == PLANE)
		object_normal = (t_tuple){{0, 1, 0, 0}};
	else
	{
		// dist = powf(object_point.x, 2) + powf(object_point.z, 2);
		dist = object_point.x * object_point.x +
			object_point.z * object_point.z;
		if (dist < 1 && object_point.y >= +1. - EPSILON)
			object_normal = (t_tuple){{0, 1, 0, 0}};
		else if (dist < 1 && object_point.y <= -1. + EPSILON)
			object_normal = (t_tuple){{0, -1, 0, 0}};
		else
			object_normal = (t_tuple){{object_point.x, 0, object_point.z, 0}};
	}
	inverse_matrix4(&object.transform, &cpy);
	transpose_matrix4(&cpy, &transposed);
	return (return_world_normal(&transposed, object_normal));
}

static t_tuple	return_world_normal(t_matrix4 const *cpy, t_tuple object_normal)
{
	t_tuple		world_normal;

	world_normal = multiply_matrix4_tuple(cpy, object_normal);
	world_normal.w = 0;
	normalize_vector(&world_normal);
	return (world_normal);
}
