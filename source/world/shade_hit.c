/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 09:56:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	shade_hit(t_world *w, t_comps comps)
{
	return (lighting(comps, w->light, is_shadowed(w, comps.over_point, comps)));
}
