/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 23:21:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	transform(t_tuple *dst, t_tuple *vector, t_tuple *point)
{
	t_matrix	*mtx;

	mtx = NULL;
	mtx = translation(vector);
	if (!mtx)
		return (NULL);
	multiply_matrix_tuple(dst, mtx, point);
	free(mtx);
	return (0);
}
