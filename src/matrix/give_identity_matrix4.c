/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_identity_matrix4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:41:41 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:00:10 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <header.h>

t_matrix4	*give_identity_matrix4(t_matrix4 *dst)
{
	int	i;

	ft_bzero(dst, sizeof(t_matrix4));
	i = -1;
	while (++i < 4)
		(*dst)[i][i] = 1;
	return (dst);
}
