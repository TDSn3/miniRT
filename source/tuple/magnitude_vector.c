/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 16:49:46 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	magnitude_vector(t_tuple *tuple)
{
	double	v;

	v = sqrt(pow(tuple->x, 2)
			+ pow(tuple->y, 2)
			+ pow(tuple->z, 2)
			+ pow(tuple->w, 2));
	return (v);
}
