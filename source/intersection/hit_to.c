/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:29:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 16:42:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	*hit_to(t_to *list)
{
	t_to	*ret;
	t_to	*copyto;

	ret = NULL;
	ret = calloc(1, sizeof(t_to));
	copyto = list;
	if (!list)
		return (NULL);
	ret->t = FLT_MAX;
	ret->object = NULL;
	ret->prev = NULL;
	ret->next = NULL;
	while (copyto)
	{
		if (copyto->t < ret->t && copyto->t >= 0)
		{
			ret->t = copyto->t;	
			ret->object = copyto->object;
		}
		copyto = copyto->next;
	}
	return (ret);
}
