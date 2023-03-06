/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:11 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:14:32 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = (char *)s + ft_strlen(s);
	while (result >= s)
	{
		if (*result == (char)c)
			return (result);
		result--;
	}
	return (NULL);
}
