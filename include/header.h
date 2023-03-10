/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 22:27:50 by rcatini          ###   ########.fr       */
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


typedef enum e_parameter {
	DEC,
	DEC_3,
	COLOR,
}	t_parameter;

typedef t_bgra	t_parsed_color;

typedef struct s_parsed_vector
{
	double	x;
	double	y;
	double	z;
}	t_parsed_vector;

typedef struct s_parsed_ambient
{
	int					initialized;
	double				intensity;
	t_parsed_color		color;
}	t_parsed_ambient;

typedef struct s_parsed_light
{
	int					initialized;
	t_parsed_vector		position;
	double				intensity;
	t_parsed_color		color;
}	t_parsed_light;

typedef struct s_parsed_camera
{
	int					initialized;
	t_parsed_vector		position;
	t_parsed_vector		direction;
	double				fov_degrees;
}	t_parsed_camera;

typedef struct s_parsed_object
{
	t_type						type;
	t_parsed_vector				position;
	t_parsed_color				color;
	t_parsed_vector				direction;
	double						radius;
	double						height;
	struct s_parsed_object		*next;
}	t_parsed_object;

typedef struct s_parsed_scene
{
	t_parsed_object		*objects;
	t_parsed_light		light;
	t_parsed_camera		camera;
	t_parsed_ambient	ambient;
}	t_parsed_scene;

typedef char	*(*t_parse)(t_parsed_scene *, char **);

int		parse_scene(char *filename, t_parsed_scene *scene);
char	*parse_sphere(t_parsed_scene *scene, char **tokens);
char	*parse_plane(t_parsed_scene *scene, char **tokens);
char	*parse_cylinder(t_parsed_scene *scene, char **tokens);
char	*parse_ambient(t_parsed_scene *scene, char **tokens);
char	*parse_camera(t_parsed_scene *scene, char **tokens);
char	*parse_light(t_parsed_scene *scene, char **tokens);
void	free_tokens(char **tokens);
void	clean_line(char *line);
int		count_tokens(char **tokens);
int		parse_items(int n, char **tokens, const t_parameter *syntax,
			void **params);

void	print_objects(t_parsed_scene const *scene);
int	init_all_data(t_all_data *all_data, t_parsed_scene *scene);
int	init_camera(t_camera *camera, t_parsed_camera *parsed_camera);
int	init_light(t_light *light, t_parsed_light *parsed_light);
t_object	*init_objects(t_parsed_object *parsed_objects,
				t_parsed_ambient *parsed_ambient);
void	free_objects(t_parsed_object *objects);

int				equal_float(double a, double b);
void			print_canvas(t_all_data const *all_data);
t_bgra			convert_to_255(t_tuple color);
double			conv_color(double color_255);
int				key_press_hook(int keycode, t_all_data *d);
int				key_release_hook(int keycode, t_all_data *d);
int				mouse_hook(int mousecode, int x, int y, t_all_data *d);
int				red_button(t_all_data *d);
int				gen_new_img(t_all_data *all_data);

void			init_point(t_tuple *tuple, double x, double y, double z);
void			init_vector(t_tuple *tuple, double x, double y, double z);
t_tuple	t_tuple_plus(t_tuple const *left, t_tuple const *right);
t_tuple	t_tuple_minus(t_tuple const *left, t_tuple const *right);
t_tuple	t_tuple_nega(t_tuple const *tuple);
// t_tuple			t_tuple_multi_scal(t_tuple left, double right);
t_tuple	t_tuple_scale(t_tuple const *left, double right);
void			t_tuple_div_scal(t_tuple *a, t_tuple *left, double right);
// t_tuple			t_tuple_multi(t_tuple left, t_tuple right);
t_tuple	t_tuple_dot(t_tuple const *left, t_tuple const *right);

double	magnitude_vector(t_tuple const *tuple);
void	normalize_vector(t_tuple *tuple);
t_tuple	normalization_vector(t_tuple const *tuple);
double			scalar_product_vector(t_tuple *a, t_tuple *b);
t_tuple	cross_product_vector(t_tuple const *a, t_tuple const *b);

int				equal_matrix4(t_matrix4 const *a, t_matrix4 const *b);
t_matrix4		*multiply_matrix4(t_matrix4 const *left, t_matrix4 const *right,
					t_matrix4 *dst);
t_tuple			multiply_matrix4_tuple(t_matrix4 const *left,
					t_tuple const right);
// t_matrix4		*give_identity_matrix4(t_matrix4 *dst);
double	*identity_matrix(size_t n, double *dst);
t_matrix4		*transpose_matrix4(t_matrix4 const *a, t_matrix4 *dst);
double			determinant_matrix2(t_matrix2 const *a);
double			determinant_matrix3(t_matrix3 const *a);
double			determinant_matrix4(t_matrix4 const *a);
t_matrix3		*sub_matrix4(t_matrix4 const *src, size_t x_del, size_t y_del,
					t_matrix3 *dst);
t_matrix2		*sub_matrix3(t_matrix3 const *src, size_t x_del, size_t y_del,
					t_matrix2 *dst);
double			minor_matrix3(t_matrix3 const *src, size_t x_del, size_t y_del);
double			cofactor_matrix3(
					t_matrix3 const *src, size_t x_row, size_t y_column);
double			cofactor_matrix4(
					t_matrix4 const *src, size_t x_row, size_t y_column);
double			minor_matrix4(t_matrix4 const *src, size_t x_del, size_t y_del);
int				is_invertible_matrix4(t_matrix4 const *a);
t_matrix4		*inverse_matrix4(t_matrix4 const *src, t_matrix4 *dst);

t_matrix4	*translation(t_tuple const *vector, t_matrix4 *dst);
t_matrix4		*scaling(t_tuple vector, t_matrix4 *dst);
t_matrix4		*rotation_x(double deg, t_matrix4 *dst);
t_matrix4		*rotation_y(double deg, t_matrix4 *dst);
t_matrix4		*rotation_z(double deg, t_matrix4 *dst);
double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
t_matrix4		*shearing(double const f[6], t_matrix4 *dst);
t_ray			transform_ray(t_tuple vector, t_tuple point,
					t_matrix4 const *mtx);

t_tuple			position(t_tuple vector, t_tuple point, double t);
t_intersection	intersect(t_tuple vector, t_tuple point, t_object const *object);
t_object		intersection(double t, t_object *object);
void			set_transform(t_object *object, t_matrix4 *t);
void			intersect_caps(
					t_ray const *ray,
					t_object const *object,
					t_intersection *ret);

t_tuple			normal_at(t_object object, t_tuple world_point);
t_tuple			reflect(t_tuple in_vector, t_tuple normal_vector);
t_tuple			lighting(
					t_material material,
					t_light const *light, t_tuple point,
					t_tuple eyev_vector,
					t_tuple nomralv_vector,
					int in_shadow);
t_tuple	color_at(t_object const *objects, t_light const *light, t_ray const *r);

t_object	intersect_world(t_object const *objects, t_ray const *ray);
t_comps	prepare_computations(t_ray const *r, t_object const *i);
t_tuple	shade_hit(t_object const *objects, t_light const *light, t_comps comps);
t_matrix4		*view_transform(t_tuple from, t_tuple to, t_tuple up,
					t_matrix4 *dst);
t_camera	give_camera(double field_of_view);
t_ray			ray_for_pixel(t_camera const *camera, double px, double py);
void	render(t_mlx_data *mlx_data, t_camera const *camera,
			t_object const *objects, t_light const *light);
void			object_lst_clear(t_object **lst);
// t_object	*object_lst_new(t_type type, double a_intensity, t_tuple a_color);
t_object	*object_lst_new(t_type type, t_parsed_ambient const *ambient);

int	is_shadowed(t_object const *objects, t_light const *light, t_tuple point);

#endif
