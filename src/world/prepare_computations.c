/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:42:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:38:31 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Précalcule le point (dans l'espace universel) où l'intersection		  */
/*   s'est produite, le vecteur pointant vers l'œil (ou la caméra)			  */
/*   "eyev_vector" et le vecteur normal "normalv_vector".					  */
/*   La variable "inside" sera vrai (1) si l'intersection "i" calculé		  */
/*   par hit_to() se produit à l'intérieur de l'objet, et faux (0) sinon.	  */
/*   La normale "normalv_vector" est inversée lorsque l'intersection		  */
/*   se trouve à l'intérieur d'un objet, pour que la surface soit			  */
/*   éclairée correctement.													  */
/*                                                                            */
/* ************************************************************************** */
t_comps	prepare_computations(t_ray const *r, t_object const *i)
{
	t_comps	comps;
	t_tuple	epsilon;

	comps.object = *i;
	comps.point = position(r->vector, r->point, comps.object.t);
	comps.eyev_vector = t_tuple_nega(&r->vector);
	comps.normalv_vector = normal_at(*i, comps.point);
	if (scalar_product_vector(&comps.normalv_vector, &comps.eyev_vector) < 0)
	{
		comps.inside = 1;
		comps.normalv_vector = t_tuple_nega(&comps.normalv_vector);
	}
	else
		comps.inside = 0;
	epsilon = t_tuple_scale(&comps.normalv_vector, EPSILON);
	comps.over_point = t_tuple_plus(&comps.point, &epsilon);
	// comps.over_point = t_tuple_plus(&comps.point,
	// 		t_tuple_scale(&comps.normalv_vector, EPSILON));
	return (comps);
}
