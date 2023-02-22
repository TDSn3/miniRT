/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:11 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/08 13:54:29 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(char *)s1++ != *(char *)s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	return (0);
}
