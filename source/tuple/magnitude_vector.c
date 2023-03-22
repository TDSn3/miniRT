/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:39:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	magnitude_vector(t_tuple *tuple)
{
	double	v;

	v = sqrtf(powf(tuple->x, 2)
			+ powf(tuple->y, 2)
			+ powf(tuple->z, 2)
			+ powf(tuple->w, 2));
	return (v);
}
