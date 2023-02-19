/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:58:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 18:15:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	transposing_matrix(t_matrix *a)
{
	t_matrix	new_matrix;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (init_matrix(&new_matrix, a->y_size, a->x_size))
		return (1);
	while (i < a->y_size)
	{
		while (j < a->x_size)
		{
			new_matrix.tab[i][j] = a->tab[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	free_matrix(a);
	if (init_matrix(a, new_matrix.x_size, new_matrix.y_size))
		return (1);
	copy_matrix(&new_matrix, a);
	free_matrix(&new_matrix);
	return (0);
}
