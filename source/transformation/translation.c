/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:46:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 23:20:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix	*translation(t_tuple *vector)
{
	t_matrix	*mtx;

	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[0][3] = vector->x;
	mtx->tab[1][3] = vector->y;
	mtx->tab[2][3] = vector->z;
	return (mtx);
}
