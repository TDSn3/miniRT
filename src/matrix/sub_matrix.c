/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:01:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:10:34 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_var(t_ijkl *z);

t_matrix3		*sub_matrix4(t_matrix4 const *src, size_t x_del, size_t y_del, t_matrix3 *dst)
{
	t_ijkl		z;

	init_var(&z);
	while (z.k < 4)
	{
		while (z.l < 4 && z.k != x_del)
		{
			if (z.l != y_del)
			{
				(*dst)[z.i][z.j] = (*src)[z.k][z.l];
				z.j++;
			}
			z.l++;
		}
		z.j = 0;
		z.l = 0;
		if (z.k != x_del)
			z.i++;
		z.k++;
	}
	return (dst);
}

t_matrix2		*sub_matrix3(t_matrix3 const *src, size_t x_del, size_t y_del, t_matrix2 *dst)
{
	t_ijkl		z;

	init_var(&z);
	while (z.k < 3)
	{
		while (z.l < 3 && z.k != x_del)
		{
			if (z.l != y_del)
			{
				(*dst)[z.i][z.j] = (*src)[z.k][z.l];
				z.j++;
			}
			z.l++;
		}
		z.j = 0;
		z.l = 0;
		if (z.k != x_del)
			z.i++;
		z.k++;
	}
	return (dst);
}

static void	init_var(t_ijkl *z)
{
	z->i = 0;
	z->j = 0;
	z->k = 0;
	z->l = 0;
}
