/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 21:32:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	si_clear(t_intersection **lst)
{
	t_intersection	**copysi;
	t_intersection	*copysi_two;

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
