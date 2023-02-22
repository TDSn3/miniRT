/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 13:26:19 by tda-silv         ###   ########.fr       */
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
# include <float.h>

//# include <struct.h>
# include "struct.h"
# include "color.h"

# define EPSILON 0.00001

void			my_mlx_pixel_put(t_all_data *all_data, int x, int y, int color);
int				equal_float(float a, float b);
void			print_canvas(t_all_data *all_data);
t_bgra			convert_to_255(t_tuple color);

void			init_point(t_tuple *tuple, float x, float y, float z);
void			init_vector(t_tuple *tuple, float x, float y, float z);
t_tuple			t_tuple_plus(t_tuple left, t_tuple right);
t_tuple			t_tuple_minus(t_tuple left, t_tuple right);
t_tuple			t_tuple_nega(t_tuple tuple);
t_tuple			t_tuple_multi_scal(t_tuple left, float right);
void			t_tuple_div_scal(t_tuple *a, t_tuple *left, float right);
t_tuple			t_tuple_multi(t_tuple left, t_tuple right);
float			magnitude_vector(t_tuple *tuple);
t_tuple			normalization_vector(t_tuple tuple);
float			scalar_product_vector(t_tuple *a, t_tuple *b);
t_tuple			cross_product_vector(t_tuple a, t_tuple b);

t_matrix		*new_matrix(size_t x_size, size_t y_size);
t_matrix		*new_identity_matrix(void);
int				init_matrix(t_matrix *a, size_t x_size, size_t y_size);
int				free_matrix(t_matrix *a);
void			copy_matrix(t_matrix *src, t_matrix *dst);
int				equal_matrix(t_matrix *a, t_matrix *b);
void			multiply_matrix(t_matrix *a, t_matrix *left, t_matrix *right);
t_tuple			multiply_matrix_tuple(t_matrix *left, t_tuple *right);
int				transposing_matrix(t_matrix *a);
float			determinant_matrix(t_matrix *a);
t_matrix		*sub_matrix(t_matrix *src, size_t x_del, size_t y_del);
float			minor_matrix(t_matrix *src, size_t x_del, size_t y_del);
float			cofactor_matrix(t_matrix *src, size_t x_row, size_t y_column);
int				is_invertible_matrix(t_matrix *a);
t_matrix		*inverse_matrix(t_matrix *src);
t_matrix		*inverse_matrix_free(t_matrix *src);

void			transform(t_tuple *dst, t_matrix *mtx, t_tuple *point);
t_matrix		*translation(t_tuple vector);
t_matrix		*scaling(t_tuple vector);
t_matrix		*rotation_x(float deg);
t_matrix		*rotation_y(float deg);
t_matrix		*rotation_z(float deg);
float			deg_to_rad(float deg);
float			rad_to_deg(float rad);
t_matrix		*shearing(t_6f f);
t_ray			transform_ray(t_tuple vector, t_tuple point, t_matrix *mtx);

t_tuple			position(t_tuple vector, t_tuple point, float t);
t_object		give_sphere(unsigned int id, t_tuple position);
t_intersection	intersect(t_tuple vector, t_tuple point, t_object *sphere);
t_to			intersection(float t, t_object *object);
t_to			hit(t_intersection *list);
void			set_transform(t_object *object, t_matrix *t);

int				si_add_back(t_intersection **lst, t_intersection *new);
size_t			si_size(t_intersection *lst);
t_intersection	*si_new(t_3f t, t_object *object);
t_intersection	*si_last(t_intersection *lst);
t_intersection	*si_find_content(t_intersection *lst, unsigned int object_id);
void			si_clear(t_intersection **lst);
void			si_clear_one(t_intersection **lst, unsigned int object_id);

t_tuple			normal_at(t_object sphere, t_tuple world_point);
t_tuple			reflect(t_tuple in_vector, t_tuple normal_vector);
t_tuple			lighting(t_material material, t_light light, t_tuple point, t_tuple eyev_vector, t_tuple nomralv_vector);

t_to			*intersect_world(t_world *world, t_ray ray);

t_object		*so_new(unsigned int id, t_type type);
int				so_add_back(t_object **lst, t_object *new);
t_object		*so_last(t_object *lst);
size_t			so_size(t_object *lst);
void			so_clear(t_object **lst);

t_to			*sto_new(float t, t_object *object);
int				sto_add_back(t_to **lst, t_to *new);
t_to			*sto_last(t_to *lst);
size_t			sto_size(t_to *lst);
void			sto_clear(t_to **lst);

#endif
