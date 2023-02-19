/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 19:59:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	*ft_calloc(size_t nmemb, size_t size);
static void	ft_bzero(void *s, size_t n);

t_matrix	*new_matrix(size_t x_size, size_t y_size)
{
	t_matrix	*mtx;

	if (x_size == 0 || y_size == 0)
		return (NULL);
	mtx = ft_calloc(1, sizeof(t_matrix));
	if (!mtx || init_matrix(mtx, x_size, y_size))
		return (NULL);
	return (mtx);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
