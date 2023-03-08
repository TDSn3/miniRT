/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:34 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

//   Imprécis
//
//t_tuple	normalization_vector(t_tuple tuple)
//{
//	t_tuple	ret;
//	double	v;
//
//	v = magnitude_vector(&tuple);
//	ret.x = tuple.x / v;
//	ret.y = tuple.y / v;
//	ret.z = tuple.z / v;
//	ret.w = tuple.w / v;
//	return (ret);
//}

t_tuple	normalization_vector(t_tuple tuple)
{
	t_tuple	ret;
	double	len;

	len = sqrtf(tuple.x * tuple.x + tuple.y * tuple.y + tuple.z * tuple.z);
	ret.x = tuple.x / len;
	ret.y = tuple.y / len;
	ret.z = tuple.z / len;
	ret.w = tuple.w / len;
	return (ret);
}
