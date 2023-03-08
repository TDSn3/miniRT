/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_identity_matrix4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:41:41 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:05:44 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <header.h>

t_matrix4	*give_identity_matrix4(t_matrix4 *dst)
{
	ft_bzero(dst, sizeof(t_matrix4));
	(*dst)[0][0] = 1;
	(*dst)[1][1] = 1;
	(*dst)[2][2] = 1;
	(*dst)[3][3] = 1;
	return (dst);
}
