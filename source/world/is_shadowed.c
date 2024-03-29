/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:09:43 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/19 10:13:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   "v" = la distance entre le point et la source de lumière				  */
/*   en soustrayant "world->light.position" par "point".					  */
/*   "distance" = la magnitude du vecteur "v".								  */
/*   "direction" = normalisation de "v".									  */
/*   Créez un rayon "r" du point vers la source de lumière avec				  */
/*   la normalisation du le vecteur "v".									  */
/*   Utilise la fonciton intersect_world() avec "world" et "direction".		  */
/*   Vérifie s'il y a une correspondance avec hit_to(), si c'est le cas		  */
/*   et si "h->t" est inférieur à distance l'impact se situe entre le point	  */
/*   et la source de lumière, et le point est dans l'ombre.					  */
/*                                                                            */
/* ************************************************************************** */
int	is_shadowed(t_world *world, t_tuple point, t_comps comps)
{
	t_tuple	v;
	t_tuple	direction;
	t_ray	r;
	t_to	inter;

	v = t_tuple_minus(world->light.position, point);
	direction = normalization_vector(v);
	r.point = point;
	r.vector = direction;
	inter = intersect_world(world, r);
	if (inter.t < comps.distance && !equal_double(inter.t, 0))
		return (1);
	else
		return (0);
}
