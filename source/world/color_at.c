/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:48:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 20:00:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	color_at(t_world *w, t_ray r)
{
	t_to	*inter;
	t_to	t;
	t_comps	comps;
	t_tuple	ret;

	inter = intersect_world(w, r);
	if (!inter)
		return ((t_tuple){0});
	t = hit_to(inter);
	if (t.t == NAN || t.t == 0)
		return ((t_tuple){0});
	comps = prepare_computations(r, &t);
	ret = shade_hit(*w, comps);
	sto_clear(&inter);
	return (ret);
}
