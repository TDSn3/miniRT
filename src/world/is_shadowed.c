/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:09:43 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:40:44 by roberto          ###   ########.fr       */
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

int	is_shadowed(t_object const *objects, t_light const *light, t_tuple point)
{
	t_tuple		v;
	double		distance;
	t_tuple		direction;
	t_ray		r;
	t_object	inter;

	v = t_tuple_minus(&light->position, &point);
	distance = magnitude_vector(&v);
	direction = normalization_vector(&v);
	r.point = point;
	r.vector = direction;
	inter = intersect_world(objects, &r);
	if (inter.t < distance && inter.t > 0)
		return (1);
	else
		return (0);
}
