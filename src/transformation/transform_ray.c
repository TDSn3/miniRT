/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 18:19:06 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_ray	transform_ray(t_tuple const vector, t_tuple const point, t_matrix4 const *mtx)
{
	t_ray	ret;

	if (mtx)
	{
		ret.vector = multiply_matrix4_tuple(mtx, vector);
		ret.point = multiply_matrix4_tuple(mtx, point);
	}
	else
	{
		ret.vector = vector;
		ret.point = point;
	}
	return (ret);
}
