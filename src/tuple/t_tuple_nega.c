/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_nega.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:30:27 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

t_tuple	t_tuple_nega(t_tuple const *tuple)
{
	assert(tuple->w == 0 || tuple->w == 1);
	return ((t_tuple){{-tuple->x, -tuple->y, -tuple->z, -tuple->w}});
}
