/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:24:16 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	shade_hit(t_world const *w, t_comps comps)
{
	return (lighting(comps.object.material, w->light, comps.over_point,
			comps.eyev_vector, comps.normalv_vector,
			is_shadowed(w, comps.over_point)));
}
