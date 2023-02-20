/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:18:49 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 19:20:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   t   distance															  */
/*                                                                            */
/*   vector + point = rayon													  */
/*                                                                            */
/*   Multiplie la direction du rayon par t pour trouver la distance totale	  */
/*   parcourue, puis l'ajoute à l'origine du rayon.							  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	position(t_tuple vector, t_tuple point, float t)
{
	t_tuple	next_pos;

	init_point(&next_pos, 0, 0, 0);
	t_tuple_multi_scal(&next_pos, &vector, t);
	t_tuple_plus(&next_pos, &point, &next_pos);
	return (next_pos);
}
