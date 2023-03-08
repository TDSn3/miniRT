/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:07:33 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	equal_matrix4(t_matrix4 const *a, t_matrix4 const *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((*a)[i][j] != (*b)[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
