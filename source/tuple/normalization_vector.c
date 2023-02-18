/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:59:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	normalization_vector(t_tuple *tuple)
{
	float	v;

	v = magnitude_vector(tuple);
	tuple->x = tuple->x / v;
	tuple->y = tuple->y / v;
	tuple->z = tuple->z / v;
	tuple->w = tuple->w / v;
}
