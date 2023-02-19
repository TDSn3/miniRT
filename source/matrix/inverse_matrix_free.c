/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:54:20 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 23:47:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	cofactor_all(t_matrix *src, t_matrix *mtx);
static void	div_by_det_all(t_matrix *src, t_matrix *mtx);

t_matrix	*inverse_matrix_free(t_matrix *src)
{
	t_matrix	*mtx;

	if (is_invertible_matrix(src) < 1)
		return (NULL);
	mtx = NULL;
	mtx = new_matrix(src->x_size, src->y_size);
	if (!mtx)
		return (NULL);
	cofactor_all(src, mtx);
	transposing_matrix(mtx);
	div_by_det_all(src, mtx);
	free(src);
	return (mtx);
}

static void	cofactor_all(t_matrix *src, t_matrix *mtx)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < src->x_size)
	{
		while (j < src->y_size)
		{
			mtx->tab[i][j] = cofactor_matrix(src, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	div_by_det_all(t_matrix *src, t_matrix *mtx)
{
	size_t		i;
	size_t		j;
	float		det;

	i = 0;
	j = 0;
	det = determinant_matrix(src);
	while (i < src->x_size)
	{
		while (j < src->y_size)
		{
			mtx->tab[i][j] = mtx->tab[i][j] / det;
			j++;
		}
		j = 0;
		i++;
	}
}
