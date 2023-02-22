/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:52:00 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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
