/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:53:30 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/04 19:14:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	determinant_matrix2(t_matrix2 a)
{
	return ((a.tab[0][0] * a.tab[1][1]) - (a.tab[0][1] * a.tab[1][0]));
}

float	determinant_matrix3(t_matrix3 a)
{
	size_t	i;
	float	det;

	i = 0;
	det = 0;
	while (i < 3)
	{
		det = det + a.tab[0][i] * cofactor_matrix3(a, 0, i);
		i++;
	}
	return (det);
}

float	determinant_matrix4(t_matrix4 a)
{
	size_t	i;
	float	det;

	i = 0;
	det = 0;
	while (i < 4)
	{
		det = det + a.tab[0][i] * cofactor_matrix4(a, 0, i);
		i++;
	}
	return (det);
}
