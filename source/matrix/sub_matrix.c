/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:01:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 00:34:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_var(t_ijkl *z);

t_matrix3	sub_matrix4(t_matrix4 src, size_t x_del, size_t y_del)
{
	t_ijkl		z;
	t_matrix3	submtx;

	init_var(&z);
	while (z.k < 4)
	{
		while (z.l < 4 && z.k != x_del)
		{
			if (z.l != y_del)
			{
				submtx.tab[z.i][z.j] = src.tab[z.k][z.l];
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
	return (submtx);
}

t_matrix2	sub_matrix3(t_matrix3 src, size_t x_del, size_t y_del)
{
	t_ijkl		z;
	t_matrix2	submtx;

	init_var(&z);
	while (z.k < 3)
	{
		while (z.l < 3 && z.k != x_del)
		{
			if (z.l != y_del)
			{
				submtx.tab[z.i][z.j] = src.tab[z.k][z.l];
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
	return (submtx);
}

static void	init_var(t_ijkl *z)
{
	z->i = 0;
	z->j = 0;
	z->k = 0;
	z->l = 0;
}
