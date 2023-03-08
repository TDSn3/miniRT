/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:58:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:01:39 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <header.h>

t_matrix4	*transpose_matrix4(t_matrix4 const *a, t_matrix4 *dst)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	ft_bzero(dst, sizeof(t_matrix4));
	while (i < 4)
	{
		while (j < 4)
		{
			(*dst)[i][j] = (*a)[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return (dst);
}
