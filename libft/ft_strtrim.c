/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:52 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:21:01 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;

	end = ft_strchr(s1, '\0');
	while (end > s1 && ft_strchr(set, *(end - 1)))
		end--;
	while (s1 < end && ft_strchr(set, *s1))
		s1++;
	return (ft_substr(s1, 0, end - s1));
}
