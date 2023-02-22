/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 12:48:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	so_clear(t_object **lst)
{
	t_object	**copysi;
	t_object	*copysi_two;

	copysi = lst;
	if (!*lst)
		return ;
	while (*copysi)
	{
		copysi_two = (*copysi)->next;
		free((*copysi)->transform);
		free(*copysi);
		*copysi = copysi_two;
	}
	*lst = NULL;
}
