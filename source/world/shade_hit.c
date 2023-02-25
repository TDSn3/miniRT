/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/25 09:27:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	shade_hit(t_world w, t_comps comps)
{
	return (lighting(comps.object.material, w.light, comps.point, comps.eyev_vector, comps.normalv_vector));
}
