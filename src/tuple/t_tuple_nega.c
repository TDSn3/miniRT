/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_nega.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:30:30 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	t_tuple_nega(t_tuple const *tuple)
{
	return ((t_tuple){{-tuple->x, -tuple->y, -tuple->z, -tuple->w}});
}
