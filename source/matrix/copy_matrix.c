/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:45:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 18:12:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	copy_matrix(t_matrix *src, t_matrix *dst)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (src->x_size != dst->x_size || src->y_size != dst->y_size)
		return ;
	while (i < src->x_size)
	{
		while (j < src->y_size)
		{
			dst->tab[i][j] = src->tab[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
