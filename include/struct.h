/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:06:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 05:40:05 by roberto          ###   ########.fr       */
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

typedef double	t_matrix4[4][4];
typedef double	t_matrix3[3][3];
typedef double	t_matrix2[2][2];

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
	struct s_object	*next;
	double			t;
}	t_object;


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
	t_object		*objects;
	t_light			light;
	t_camera		camera;
}	t_all_data;

#endif