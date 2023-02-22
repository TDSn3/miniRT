/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:16:12 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:16:13 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (result)
		ft_memcpy(result, s, len + 1);
	return (result);
}
