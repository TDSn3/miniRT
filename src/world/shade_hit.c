/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 23:11:19 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	shade_hit(t_object const *objects, t_light const *light, t_comps comps)
{
	return (lighting(comps.object.material, light, comps.over_point,
			comps.eyev_vector, comps.normalv_vector,
			is_shadowed(objects, light, comps.over_point)));
}
