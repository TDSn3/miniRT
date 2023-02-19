/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:51:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 21:07:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Matrice de 3x3.														  */
/*                                                                            */
/* ************************************************************************** */
float	cofactor_matrix(t_matrix *src, size_t x_row, size_t y_column)
{
	float	minor;
	float	sign;

	if ((x_row + y_column) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	minor = minor_matrix(src, x_row, y_column);
	return (minor * sign);
}
