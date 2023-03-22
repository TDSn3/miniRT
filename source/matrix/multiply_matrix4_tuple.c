/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix4_tuple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:14:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/04 19:14:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_tuple	multiply_matrix4_tuple(t_matrix4 left, t_tuple right)
{
	t_tuple	ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ret.tuple[0] = 0;
	ret.tuple[1] = 0;
	ret.tuple[2] = 0;
	ret.tuple[3] = 0;
	while (i < 4 && i < 4)
	{
		while (j < 4 && j < 4)
		{
			ret.tuple[i] += left.tab[i][j] * right.tuple[j];
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}
