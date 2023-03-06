/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:54:20 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 00:35:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	cofactor_all(t_matrix4 *src, t_matrix4 *mtx);
static void	div_by_det_all(t_matrix4 *src, t_matrix4 *mtx);

t_matrix4	*inverse_matrix4(t_matrix4 src, t_matrix4 *dst)
{
	t_matrix4	mtx;

	if (is_invertible_matrix4(src) < 1)
		return (NULL);
	mtx = (t_matrix4){0};
	cofactor_all(&src, &mtx);
	*dst = transpose_matrix4(mtx);
	div_by_det_all(&src, dst);
	return (dst);
}

static void	cofactor_all(t_matrix4 *src, t_matrix4 *mtx)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			mtx->tab[i][j] = cofactor_matrix4(*src, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	div_by_det_all(t_matrix4 *src, t_matrix4 *mtx)
{
	size_t		i;
	size_t		j;
	float		det;

	i = 0;
	j = 0;
	det = determinant_matrix4(*src);
	while (i < 4)
	{
		while (j < 4)
		{
			mtx->tab[i][j] = mtx->tab[i][j] / det;
			j++;
		}
		j = 0;
		i++;
	}
}
