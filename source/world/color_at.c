/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:48:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/18 16:35:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	color_at(t_world *w, t_ray r)
{
	t_to	inter;
	t_comps	comps;
	t_tuple	ret;

	inter = intersect_world(w, r);
	if (inter.t == DBL_MAX)
		return ((t_tuple){0});
	comps = prepare_computations(r, &inter);
	ret = shade_hit(w, comps);
	return (ret);
}
