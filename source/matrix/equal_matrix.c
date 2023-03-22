/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:02:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	equal_matrix4(t_matrix4 a, t_matrix4 b)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (a.tab[i][j] != b.tab[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
