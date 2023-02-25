/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:42:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/25 09:28:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_comps	prepare_computations(t_ray r, t_to *i)
{
	t_comps	comps;

	comps.t = i->t;
	comps.object = *i->object;
	comps.point = position(r.vector, r.point, comps.t);
	comps.eyev_vector = t_tuple_nega(r.vector);
	comps.normalv_vector = normal_at(*i->object, comps.point);
	if (scalar_product_vector(&comps.normalv_vector, &comps.eyev_vector) < 0)
	{
		comps.inside = 1;
		comps.normalv_vector = t_tuple_nega(comps.normalv_vector);
	}
	else
		comps.inside = 0;
	return (comps);
}
