/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:43 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	t_tuple_plus(t_tuple const *left, t_tuple const *right)
{
	return ((t_tuple){{
			left->x + right->x,
			left->y + right->y,
			left->z + right->z,
			left->w + right->w}});
}
