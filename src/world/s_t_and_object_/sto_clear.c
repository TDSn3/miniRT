/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sto_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 13:16:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	sto_clear(t_to **lst)
{
	t_to	**copysi;
	t_to	*copysi_two;

	copysi = lst;
	if (!*lst)
		return ;
	while (*copysi)
	{
		copysi_two = (*copysi)->next;
		free(*copysi);
		*copysi = copysi_two;
	}
	*lst = NULL;
}
