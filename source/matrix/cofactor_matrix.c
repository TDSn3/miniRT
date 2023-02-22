/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:51:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 21:53:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	cofactor_matrix3(t_matrix3 src, size_t x_row, size_t y_column)
{
	float	minor;
	float	sign;

	if ((x_row + y_column) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	minor = minor_matrix3(src, x_row, y_column);
	return (minor * sign);
}

float	cofactor_matrix4(t_matrix4 src, size_t x_row, size_t y_column)
{
	float	minor;
	float	sign;

	if ((x_row + y_column) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	minor = minor_matrix4(src, x_row, y_column);
	return (minor * sign);
}

