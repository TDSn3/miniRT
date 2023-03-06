/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:14:37 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 06:07:58 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double	ft_atod(const char *str)
{
	long long	n;
	int			sign;
	double		pow;

	n = 0;
	pow = 1;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		n = n * 10 + *str++ - '0';
	if (*str && *str++ == '.')
	{
		while (ft_isdigit(*str))
		{
			pow *= 10;
			n = n * 10 + *str++ - '0';
		}
	}
	if (*str)
		return (NAN);
	return (n * sign / pow);
}

