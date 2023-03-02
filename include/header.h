/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 14:36:47 by tda-silv         ###   ########.fr       */
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

# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

# include "matrix.h"
# include "comps.h"
# include "struct.h"
# include "colors.h"

void			init_all(
					t_all_data *all_data,
					t_mwi *mwi,
					t_data_mlx_img *data_img,
					t_dk *data_key);
void			my_mlx_pixel_put(t_all_data *all_data, int x, int y, int color);
int				equal_float(float a, float b);
void			print_canvas(t_all_data *all_data);
t_bgra			convert_to_255(t_tuple color);
float			conv_color(float color_255);
int				key_hook(int keycode, t_all_data *d);
int				red_button(t_mwi *mwi);
int				gen_new_img(t_all_data *all_data);

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

int				equal_matrix4(t_matrix4 a, t_matrix4 b);
t_matrix4		multiply_matrix4(t_matrix4 left, t_matrix4 right);
t_tuple			multiply_matrix4_tuple(t_matrix4 left, t_tuple right);
t_matrix4		give_identity_matrix4(void);
t_matrix4		transpose_matrix4(t_matrix4 a);
float			determinant_matrix2(t_matrix2 a);
float			determinant_matrix3(t_matrix3 a);
float			determinant_matrix4(t_matrix4 a);
t_matrix3		sub_matrix4(t_matrix4 src, size_t x_del, size_t y_del);
t_matrix2		sub_matrix3(t_matrix3 src, size_t x_del, size_t y_del);
float			minor_matrix3(t_matrix3 src, size_t x_del, size_t y_del);
float			cofactor_matrix3(t_matrix3 src, size_t x_row, size_t y_column);
float			cofactor_matrix4(t_matrix4 src, size_t x_row, size_t y_column);
float			minor_matrix4(t_matrix4 src, size_t x_del, size_t y_del);
int				is_invertible_matrix4(t_matrix4 a);
t_matrix4		*inverse_matrix4(t_matrix4 src, t_matrix4 *dst);

t_tuple			transform(t_matrix4 mtx, t_tuple point);
t_matrix4		translation(t_tuple vector);
t_matrix4		scaling(t_tuple vector);
t_matrix4		rotation_x(float deg);
t_matrix4		rotation_y(float deg);
t_matrix4		rotation_z(float deg);
float			deg_to_rad(float deg);
float			rad_to_deg(float rad);
t_matrix4		shearing(t_6f f);
t_ray			transform_ray(t_tuple vector, t_tuple point, t_matrix4 *mtx);

t_tuple			position(t_tuple vector, t_tuple point, float t);
t_intersection	intersect(t_tuple vector, t_tuple point, t_object *object);
t_to			intersection(float t, t_object *object);
void			set_transform(t_object *object, t_matrix4 *t);
void			intersect_caps(
					t_ray ray,
					t_object *object,
					t_intersection *ret);

int				si_add_back(t_intersection **lst, t_intersection *new);
size_t			si_size(t_intersection *lst);
t_intersection	*si_new(t_3f t, t_object *object);
t_intersection	*si_last(t_intersection *lst);
void			si_clear(t_intersection **lst);

t_tuple			normal_at(t_object object, t_tuple world_point);
t_tuple			reflect(t_tuple in_vector, t_tuple normal_vector);
t_tuple			lighting(t_material material, t_light light, t_tuple point, t_tuple eyev_vector, t_tuple nomralv_vector,  int in_shadow);
t_tuple			color_at(t_world *w, t_ray r);

// t_to			*intersect_world(t_world *world, t_ray ray);
t_to			intersect_world(t_world *world, t_ray ray);
t_comps			prepare_computations(t_ray r, t_to *i);
t_tuple			shade_hit(t_world w, t_comps comps);
t_to			*hit_to(t_to *list);
t_matrix4		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_camera		give_camera(float hsize, float vsize, float field_of_view);
t_ray			ray_for_pixel(t_camera camera, float px, float py);
void			render(t_all_data *all_data, t_camera camera, t_world *world);

t_object		*so_new(t_type type, t_dp dp);
int				so_add_back(t_object **lst, t_object *new);
t_object		*so_last(t_object *lst);
size_t			so_size(t_object *lst);
void			so_clear(t_object **lst);

t_to			*sto_new(float t, t_object *object);
int				sto_add_back(t_to **lst, t_to *new);
t_to			*sto_last(t_to *lst);
size_t			sto_size(t_to *lst);
void			sto_clear(t_to **lst);
void			sto_sort(t_to **lst);

int				is_shadowed(t_world *world, t_tuple point);

void			main_exec_thread(t_dmet *dmet);
void			*exec_thread1(void *data);
void			*exec_thread2(void *data);
void			*exec_thread3(void *data);
void			*exec_thread4(void *data);
void			*exec_thread5(void *data);
void			*exec_thread6(void *data);
void			*exec_thread7(void *data);
void			*exec_thread8(void *data);
void			*exec_thread9(void *data);
void			*exec_thread10(void *data);
void			*exec_thread11(void *data);
void			*exec_thread12(void *data);

#endif
