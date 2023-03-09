/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:06:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 02:55:03 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define HEIGHT 200
# define WIDTH 400
# define EPSILON 0.00001

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_type;

typedef union s_tuple
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	double		tuple[4];
}	t_tuple;

typedef struct s_ray
{
	t_tuple		vector;
	t_tuple		point;
}	t_ray;

typedef struct s_light
{
	t_tuple		intensity;
	t_tuple		position;
}	t_light;

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	t_tuple	a_color;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef union s_bgra
{
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
	unsigned int		bgra;
}	t_bgra;

/* ************************************************************************** */
/*                                                                            */
/*   hsize   		 taille horizontale du canevas en pixels                  */
/*   vsize   		 taille verticale du canevas du canevas                   */
/*   field_of_view   angle qui décrit ce que la caméra peut voir              */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_camera
{
	double		field_of_view;
	t_matrix4	transform;
	t_matrix4	inverse;
	double		half_width;
	double		half_height;
	double		pixel_size;
}	t_camera;

/* ************************************************************************** */
/*                                                                            */
/*   Par défaut   transform = new_identity_matrix()                           */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_object
{
	t_type			type;
	t_tuple			position;
	t_matrix4		transform;
	t_matrix4		inverse;
	t_material		material;
	int				cyl_closed;
	struct s_object	*prev;
	struct s_object	*next;
	double			t;
}	t_object;

typedef struct s_world
{
	t_object	*lst_object;
	t_light		*light;
}	t_world;

/* ************************************************************************** */
/*                                                                            */
/*   t.a      nombre d'intersection                                           */
/*   t.b      distance entre l'origine du rayon et l'intersection 1           */
/*   t.c      distance entre l'origine du rayon et l'intersection 2           */
/*   object   type de l'objet									              */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_intersection
{
	double					t[3];
	t_object				*object;
}	t_intersection;

typedef struct s_data_key
{
	double	c_add_pos_x;
	double	c_add_pos_y;
	double	c_add_pos_z;
	double	c_add_to_x;
	double	c_add_to_y;
	double	c_add_to_z;
	double	c_add_fov;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_up;
	int		key_down;
	int		key_shift;
}	t_dk;

typedef struct s_data_parsing
{
	double	ambient;
	t_tuple	a_color;
	t_tuple	c_position;
	t_tuple	c_to;
	double	c_fov;
	t_tuple	l_position;
	double	l_i;
	t_tuple	l_color;
}	t_dp;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx_data;

typedef struct s_all_data
{
	t_mlx_data		mlx_data;
	t_dk			data_key;
	t_object		*list_object;
}	t_all_data;

#endif