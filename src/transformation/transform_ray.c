/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 06:24:28 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_ray	transform_ray(t_tuple vector, t_tuple point, t_matrix4 const *mtx)
{
	t_tuple	vector2;
	t_tuple	point2;
	t_ray	ret;

	if (mtx)
	{
		vector2 = transform(mtx, vector);
		point2 = transform(mtx, point);
		ret.x = vector2.x;
		ret.y = vector2.y;
		ret.z = vector2.z;
		ret.w = vector2.w;
		ret.x2 = point2.x;
		ret.y2 = point2.y;
		ret.z2 = point2.z;
		ret.w2 = point2.w;
	}
	else
	{
		ret.vector = vector;
		ret.point = point;
	}
	return (ret);
}
