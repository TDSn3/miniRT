/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:58:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:04:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	transpose_matrix4(t_matrix4 a)
{
	t_matrix4	mtx;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	mtx = (t_matrix4){0};
	while (i < 4)
	{
		while (j < 4)
		{
			mtx.tab[i][j] = a.tab[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return (mtx);
}
