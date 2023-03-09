/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:46:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:00:14 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	*translation(t_tuple vector, t_matrix4 *dst)
{
	// give_identity_matrix4(dst);
	identity_matrix(4, (double *)dst);
	(*dst)[0][3] = vector.x;
	(*dst)[1][3] = vector.y;
	(*dst)[2][3] = vector.z;
	return (dst);
}
