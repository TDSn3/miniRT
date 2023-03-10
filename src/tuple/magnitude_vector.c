/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:26:23 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

double	magnitude_vector(t_tuple const *tuple)
{
	assert(tuple->w == 0);
	return (sqrtf(
			tuple->x * tuple->x
			+ tuple->y * tuple->y
			+ tuple->z * tuple->z
			+ tuple->w * tuple->w));
}
