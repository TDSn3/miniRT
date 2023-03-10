/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:31:32 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

t_tuple	t_tuple_plus(t_tuple const *left, t_tuple const *right)
{
	assert((left->w == 1 && right->w == 0) || (left->w == 0 && right->w == 0));
	return ((t_tuple){{
			left->x + right->x,
			left->y + right->y,
			left->z + right->z,
			left->w + right->w}});
}
