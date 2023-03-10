/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invertible_matrix4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:38:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	is_invertible_matrix4(t_matrix4 const *a)
{
	double	det;

	det = determinant_matrix4(a);
	if (det == NAN)
		return (-1);
	else if (det == 0)
		return (0);
	else
		return (1);
}
