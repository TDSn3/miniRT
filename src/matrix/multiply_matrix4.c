/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:14:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 22:24:00 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <libft.h>

t_matrix4	*multiply_matrix4(t_matrix4 const *left, t_matrix4 const *right,
				t_matrix4 *dst)
{
	t_matrix4	tmp;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			tmp[i][j] = 0;
			while (k < 4)
			{
				tmp[i][j] += (*left)[i][k] * (*right)[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_memcpy(dst, &tmp, sizeof(*dst));
	return (dst);
}
