/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:53:30 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 21:31:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	determinant_matrix(t_matrix *a)
{
	size_t	i;
	float	det;

	i = 0;
	det = 0;
	if (a->x_size < 2 || a->y_size < 2)
		return (NAN);
	if (a->x_size == 2 || a->y_size == 2)
		return ((a->tab[0][0] * a->tab[1][1]) - (a->tab[0][1] * a->tab[1][0]));
	else
	{
		while (i < a->x_size)
		{
			det = det + a->tab[0][i] * cofactor_matrix(a, 0, i);
			i++;
		}
		return (det);
	}
}
