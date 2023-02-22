/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:22:03 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:22:13 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = malloc(ft_strlen(s) + 1);
	if (result)
	{
		i = 0;
		while (s[i])
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
