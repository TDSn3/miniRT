/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:29:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 22:51:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	hit(t_intersection *list)
{
	t_to			ret;
	t_intersection	*copysi;

	copysi = list;
	if (!list)
		return ((t_to){NAN});
	ret.t = FLT_MAX;
	while (copysi)
	{
		if (copysi->t.b < ret.t && copysi->t.b >= 0)
		{
			ret.t = copysi->t.b;
			ret.object = copysi->object;
		}
		if (copysi->t.c < ret.t && copysi->t.c >= 0)
		{
			ret.t = copysi->t.c;
			ret.object = copysi->object;
		}
		copysi = copysi->next;
	}
	return (ret);
}
