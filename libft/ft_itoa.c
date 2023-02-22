/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:21:40 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:21:50 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	get_size(int n, int *sign)
{
	int	size;

	*sign = +1;
	size = 0;
	if (n < 0)
	{
		*sign = -1;
		n = -n;
		size++;
	}
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		sign;
	char	*result;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = get_size(n, &sign);
	result = malloc(len + 1);
	if (!result)
		return (result);
	result[len] = '\0';
	if (sign < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n)
	{
		result[--len] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
