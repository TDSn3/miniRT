/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:01:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:26 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix3	*sub_matrix4(t_matrix4 const *src, size_t x_del, size_t y_del,
				t_matrix3 *dst)
{
	size_t	i_orig;
	size_t	j_orig;
	size_t	i_dst;
	size_t	j_dst;

	i_orig = -1;
	i_dst = 0;
	while (++i_orig < 4)
	{
		if (i_orig == x_del)
			continue ;
		j_orig = -1;
		j_dst = 0;
		while (++j_orig < 4)
		{
			if (j_orig == y_del)
				continue ;
			(*dst)[i_dst][j_dst] = (*src)[i_orig][j_orig];
			j_dst++;
		}
		i_dst++;
	}
	return (dst);
}

t_matrix2	*sub_matrix3(t_matrix3 const *src, size_t x_del, size_t y_del,
				t_matrix2 *dst)
{
	size_t	i_orig;
	size_t	j_orig;
	size_t	i_dst;
	size_t	j_dst;

	i_orig = -1;
	i_dst = 0;
	while (++i_orig < 3)
	{
		if (i_orig == x_del)
			continue ;
		j_orig = -1;
		j_dst = 0;
		while (++j_orig < 3)
		{
			if (j_orig == y_del)
				continue ;
			(*dst)[i_dst][j_dst] = (*src)[i_orig][j_orig];
			j_dst++;
		}
		i_dst++;
	}
	return (dst);
}
