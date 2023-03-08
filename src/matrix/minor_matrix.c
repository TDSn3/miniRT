/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:04:52 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:30 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	minor_matrix3(t_matrix3 const *src, size_t x_del, size_t y_del)
{
	t_matrix2	mtx;
	double		minor;

	sub_matrix3(src, x_del, y_del, &mtx);
	minor = determinant_matrix2(&mtx);
	return (minor);
}

double	minor_matrix4(t_matrix4 const *src, size_t x_del, size_t y_del)
{
	t_matrix3	mtx3;
	double		minor;

	sub_matrix4(src, x_del, y_del, &mtx3);
	minor = determinant_matrix3(&mtx3);
	return (minor);
}
