/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:53:30 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:28 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	determinant_matrix2(t_matrix2 const (*a))
{
	return (((*a)[0][0] * (*a)[1][1]) - ((*a)[0][1] * (*a)[1][0]));
}

double	determinant_matrix3(t_matrix3 const (*a))
{
	size_t	i;
	double	det;

	i = 0;
	det = 0;
	while (i < 3)
	{
		det = det + (*a)[0][i] * cofactor_matrix3(a, 0, i);
		i++;
	}
	return (det);
}

double	determinant_matrix4(t_matrix4 const (*a))
{
	size_t	i;
	double	det;

	i = 0;
	det = 0;
	while (i < 4)
	{
		det = det + ((*a))[0][i] * cofactor_matrix4(a, 0, i);
		i++;
	}
	return (det);
}
