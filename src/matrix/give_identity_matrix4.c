/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_identity_matrix4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:41:41 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 14:59:43 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <header.h>

double	*identity_matrix(size_t n, double *dst)
{
	size_t	i;

	ft_bzero(dst, sizeof(*dst) * n * n);
	i = -1;
	while (++i < n)
		*(dst + i * n + i) = 1;
	return (dst);
}
