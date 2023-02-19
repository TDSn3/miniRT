/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 13:03:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	equal_matrix(t_matrix *a, t_matrix *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (a->x_size != b->x_size || a->y_size != b->y_size)
		return (0);
	while (i < a->x_size)
	{
		while (j < a->y_size)
		{
			if (a->tab[i][j] != b->tab[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
