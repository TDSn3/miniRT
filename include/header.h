/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 21:26:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

//# include <struct.h>
# include "struct.h"

# define EPSILON 0.00001

void		my_mlx_pixel_put(t_all_data *all_data, int x, int y, int color);
int			equal_float(float a, float b);
void		init_point(t_tuple *tuple, float x, float y, float z);
void		init_vector(t_tuple *tuple, float x, float y, float z);
void		t_tuple_plus(t_tuple *a, t_tuple *left, t_tuple *right);
void		t_tuple_minus(t_tuple *a, t_tuple *left, t_tuple *right);
void		t_tuple_nega(t_tuple *tuple);
void		t_tuple_multi_scal(t_tuple *a, t_tuple *left, float right);
void		t_tuple_div_scal(t_tuple *a, t_tuple *left, float right);
float		magnitude_vector(t_tuple *tuple);
void		normalization_vector(t_tuple *tuple);
float		scalar_product_vector(t_tuple *a, t_tuple *b);
void		cross_product_vector(t_tuple *vector, t_tuple *a, t_tuple *b);

t_matrix	*new_matrix(size_t x_size, size_t y_size);
int			init_matrix(t_matrix *a, size_t x_size, size_t y_size);
int			free_matrix(t_matrix *a);
void		copy_matrix(t_matrix *src, t_matrix *dst);
int			equal_matrix(t_matrix *a, t_matrix *b);
void		multiply_matrix(t_matrix *a, t_matrix *left, t_matrix *right);
void		multiply_matrix_tuple(t_tuple *a, t_matrix *left, t_tuple *right);
int			transposing_matrix(t_matrix *a);
float		determinant_matrix(t_matrix *a);
t_matrix	*sub_matrix(t_matrix *src, size_t x_del, size_t y_del);
float		minor_matrix(t_matrix *src, size_t x_del, size_t y_del);
float		cofactor_matrix(t_matrix *src, size_t x_row, size_t y_column);

#endif
