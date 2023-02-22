/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_clear_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 13:26:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	si_clear_one(t_intersection **lst, unsigned int object_id)
{
	t_intersection	*si_cpy;
	int				si_size_stock;

	si_size_stock = si_size(*lst);
	si_cpy = *lst;
	if (si_size_stock == 1)
	{
		si_clear(lst);
		return ;
	}	
	while (si_cpy && si_cpy->object->id != object_id)
		si_cpy = si_cpy->next;
	if (si_cpy->object->id == object_id)
	{
		if (si_cpy->prev)
			si_cpy->prev->next = si_cpy->next;
		if (si_cpy->next)
		{
			si_cpy->next->prev = si_cpy->prev;
			if (si_cpy == *lst)
				*lst = si_cpy->next;
		}
		free(si_cpy);
	}
}
