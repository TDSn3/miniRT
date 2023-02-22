/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:33 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:20:42 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(size);
	if (result)
	{
		ft_strlcpy(result, s1, size);
		ft_strlcat(result, s2, size);
	}
	return (result);
}
