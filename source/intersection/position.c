/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:18:49 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 17:56:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   t   distance															  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	position(t_tuple vector, t_tuple point, float t)
{
	t_tuple	next_ray;

	init_point(&next_ray, 0, 0, 0);
	t_tuple_multi_scal(&next_ray, &vector, t);
	t_tuple_plus(&next_ray, &point, &next_ray);
	return (next_ray);
}
