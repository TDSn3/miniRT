/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:12:07 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/04 12:12:09 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_e;
	t_list	*tail;

	new_list = NULL;
	tail = NULL;
	while (lst)
	{
		new_e = ft_lstnew(f(lst->content));
		if (!new_e)
			break ;
		if (!new_list)
			new_list = new_e;
		if (tail)
			tail->next = new_e;
		tail = new_e;
		lst = lst->next;
	}
	if (new_list && !new_e)
		ft_lstclear(&new_list, del);
	return (new_list);
}
