/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invertible_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:38:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 22:05:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	is_invertible_matrix(t_matrix *a)
{
	float	det;

	det = determinant_matrix(a);
	if (det == NAN)
		return (-1);
	else if (det == 0)
		return (0);
	else
		return (1);
}
