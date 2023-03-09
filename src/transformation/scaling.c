/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:00:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	*scaling(t_tuple vector, t_matrix4 *dst)
{
	int	i;

	// give_identity_matrix4(dst);
	identity_matrix(4, (double *)dst);
	i = -1;
	while (++i < 3)
		(*dst)[i][i] = vector.tuple[i];
	return (dst);
}
