/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:24:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 21:30:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix4
{
	float	tab[4][4];
}	t_matrix4;

typedef struct s_matrix3
{
	float	tab[3][3];
}	t_matrix3;

typedef struct s_matrix2
{
	float	tab[2][2];
}	t_matrix2;

#endif