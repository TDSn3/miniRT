/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:26:40 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

void	normalize_vector(t_tuple *tuple)
{
	assert(tuple->w == 0);
	*tuple = t_tuple_scale(tuple, 1 / magnitude_vector(tuple));
}

t_tuple	normalization_vector(t_tuple const *tuple)
{
	assert(tuple->w == 0);
	return (t_tuple_scale(tuple, 1 / magnitude_vector(tuple)));
}
