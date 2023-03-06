/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:16:33 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:16:43 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	src_len;

	src_len = ft_strlen(s);
	if (start >= src_len)
		result = ft_strdup("");
	else
	{
		if (start + len > src_len)
			len = src_len - start;
		result = malloc(len + 1);
		if (result)
			ft_strlcpy(result, s + start, len + 1);
	}
	return (result);
}
