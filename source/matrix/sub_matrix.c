/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:01:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 20:00:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_var(t_ijkl *z, t_matrix **submtx);
static void	reset_and_incr(t_ijkl *z, size_t x_del);

t_matrix	*sub_matrix(t_matrix *src, size_t x_del, size_t y_del)
{
	t_ijkl		z;
	t_matrix	*submtx;

	init_var(&z, &submtx);
	if (src->x_size == 0 || src->y_size == 0
		|| x_del > src->x_size - 1 || y_del > src->y_size - 1)
		return (NULL);
	submtx = new_matrix(src->x_size - 1, src->y_size - 1);
	if (!submtx)
		return (NULL);
	while (z.k < src->x_size)
	{
		while (z.l < src->y_size && z.k != x_del)
		{
			if (z.l != y_del)
			{
				submtx->tab[z.i][z.j] = src->tab[z.k][z.l];
				z.j++;
			}
			z.l++;
		}
		reset_and_incr(&z, x_del);
	}
	return (submtx);
}

static void	init_var(t_ijkl *z, t_matrix **submtx)
{
	z->i = 0;
	z->j = 0;
	z->k = 0;
	z->l = 0;
	*submtx = NULL;
}

static void	reset_and_incr(t_ijkl *z, size_t x_del)
{
	z->j = 0;
	z->l = 0;
	if (z->k != x_del)
		z->i++;
	z->k++;
}