/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:14:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:09:43 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	*multiply_matrix4(t_matrix4 const *left, t_matrix4 const *right, t_matrix4 *dst)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			(*dst)[i][j] = 0;
			while (k < 4)
			{
				(*dst)[i][j] += (*left)[i][k] * (*right)[k][j];
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (dst);
}
