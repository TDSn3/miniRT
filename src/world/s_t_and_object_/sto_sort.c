/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sto_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 14:35:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	sto_sort(t_to **lst)
{
	t_to	*cpy_lst;
	t_to	*stock_prev;
	t_to	*stock_next;

	if (!lst || !*lst)
		return ;
	cpy_lst = *lst;
	stock_prev = NULL;
	while (cpy_lst)
	{
		stock_next = cpy_lst -> next;
		stock_prev = cpy_lst -> prev;
		while (stock_prev && stock_prev -> t > cpy_lst -> t)
		{
			stock_prev -> next = cpy_lst -> next;
			if (cpy_lst -> next)
				cpy_lst -> next -> prev = stock_prev;
			cpy_lst -> next = stock_prev;
			cpy_lst -> prev = stock_prev -> prev;
			stock_prev -> prev = cpy_lst;
			if (cpy_lst -> prev)
				cpy_lst -> prev->next = cpy_lst;
			stock_prev = cpy_lst -> prev;
		}
		cpy_lst = stock_next;
	}
	while ((*lst)-> prev != NULL)
		*lst = (*lst)-> prev;
}
