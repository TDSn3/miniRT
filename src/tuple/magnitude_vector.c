/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 19:11:22 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	magnitude_vector(t_tuple *tuple)
{
	float	v;

	// v = sqrtf(powf(tuple->x, 2)
	// 		+ powf(tuple->y, 2)
	// 		+ powf(tuple->z, 2)
	// 		+ powf(tuple->w, 2));
	v = sqrtf(tuple->x * tuple->x
			+ tuple->y * tuple->y
			+ tuple->z * tuple->z
			+ tuple->w * tuple->w);
	return (v);
}
