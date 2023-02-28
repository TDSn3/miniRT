/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:42:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 07:27:03 by tda-silv         ###   ########.fr       */
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
t_comps	prepare_computations(t_ray r, t_to *i)
{
	t_comps	comps;

	comps.t = i->t;
	comps.object = *i->object;
	comps.point = position(r.vector, r.point, comps.t);
	comps.eyev_vector = t_tuple_nega(r.vector);
	comps.normalv_vector = normal_at(*i->object, comps.point);
	if (scalar_product_vector(&comps.normalv_vector, &comps.eyev_vector) < 0)
	{
		comps.inside = 1;
		comps.normalv_vector = t_tuple_nega(comps.normalv_vector);
	}
	else
		comps.inside = 0;
	comps.over_point = t_tuple_plus(comps.point,
			t_tuple_multi_scal(comps.normalv_vector, EPSILON + 0.1)); // ATTENTION 0.1 a retirer
	return (comps);
}
