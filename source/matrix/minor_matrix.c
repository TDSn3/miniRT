/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:04:52 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 22:00:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	minor_matrix(t_matrix *src, size_t x_del, size_t y_del)
{
	t_matrix	*mtx;
	float		minor;

	mtx = NULL;
	mtx = sub_matrix(src, x_del, y_del);
	if (!mtx)
		return (NAN);
	minor = determinant_matrix(mtx);
	if (minor == NAN)
		return (NAN);
	free(mtx);
	return (minor);
}
