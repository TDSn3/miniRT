/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:33 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	magnitude_vector(t_tuple *tuple)
{
	double	v;

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
