/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:53:30 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 19:01:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	determinant_matrix(t_matrix *a)
{
	if (a->x_size < 2 || a->y_size < 2)
		return (NAN);
	return ((a->tab[0][0] * a->tab[1][1]) - (a->tab[0][1] * a->tab[1][0]));
}
