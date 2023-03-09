/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:19:25 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	*normalize_vector(t_tuple *tuple)
{
	double	len;

	len = magnitude_vector(tuple);
	tuple->x /= len;
	tuple->y /= len;
	tuple->z /= len;
	tuple->w /= len;
	return (tuple);
}

t_tuple	normalization_vector(t_tuple const *tuple)
{
	t_tuple	ret;
	double	len;

	len = magnitude_vector(tuple);
	ret.x = tuple->x / len;
	ret.y = tuple->y / len;
	ret.z = tuple->z / len;
	ret.w = tuple->w / len;
	return (ret);
}
