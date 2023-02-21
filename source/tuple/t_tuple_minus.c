/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 12:37:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	t_tuple_minus(t_tuple left, t_tuple right)
{
	t_tuple	ret;

	ret.x = left.x - right.x;
	ret.y = left.y - right.y;
	ret.z = left.z - right.z;
	ret.w = left.w - right.w;
	return (ret);
}
