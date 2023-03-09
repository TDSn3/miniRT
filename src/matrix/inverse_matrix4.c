/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:54:20 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:05:54 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <header.h>

static void	cofactor_all(t_matrix4 const *src, t_matrix4 *mtx);
static void	div_by_det_all(t_matrix4 const *src, t_matrix4 *mtx);

t_matrix4	*inverse_matrix4(t_matrix4 const *src, t_matrix4 *dst)
{
	t_matrix4	mtx;

	if (is_invertible_matrix4(src) < 1)
		return (NULL);
	ft_bzero(mtx, sizeof(t_matrix4));
	cofactor_all(src, &mtx);
	transpose_matrix4(&mtx, dst);
	div_by_det_all(src, dst);
	return (dst);
}

static void	cofactor_all(t_matrix4 const *src, t_matrix4 *mtx)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			(*mtx)[i][j] = cofactor_matrix4(src, i, j);
	}
}

static void	div_by_det_all(t_matrix4 const *src, t_matrix4 *mtx)
{
	size_t		i;
	size_t		j;
	double		det;

	i = 0;
	j = 0;
	det = determinant_matrix4(src);
	while (i < 4)
	{
		while (j < 4)
		{
			(*mtx)[i][j] = (*mtx)[i][j] / det;
			j++;
		}
		j = 0;
		i++;
	}
}
