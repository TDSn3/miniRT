/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:04:52 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 00:35:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	minor_matrix3(t_matrix3 src, size_t x_del, size_t y_del)
{
	t_matrix2	mtx;
	double		minor;

	mtx = sub_matrix3(src, x_del, y_del);
	minor = determinant_matrix2(mtx);
	return (minor);
}

double	minor_matrix4(t_matrix4 src, size_t x_del, size_t y_del)
{
	t_matrix3	mtx3;
	double		minor;

	mtx3 = sub_matrix4(src, x_del, y_del);
	minor = determinant_matrix3(mtx3);
	return (minor);
}
