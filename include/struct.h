/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:06:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 11:27:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define HEIGHT 240
# define WIDTH 427
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
	union
	{
		struct
		{
			double	x;
			double	y;
			double	z;
			double	w;
		};
		double		tab[4];
		t_tuple		vector;
	};
	union
	{
		struct
		{
			double	x2;
			double	y2;
			double	z2;
			double	w2;
		};
		double		tab2[4];
		t_tuple		point;
	};
}	t_ray;

typedef struct s_light
{
	union
	{
		struct
		{
			double	x;
			double	y;
			double	z;
			double	w;
		};
		double		tab[4];
		t_tuple		intensity;
	};
	union
	{
		struct
		{
			double	x2;
			double	y2;
			double	z2;
			double	w2;
		};
		double		tab2[4];
		t_tuple		position;
	};
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

typedef union u_bgra
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

typedef union s_3f
{
	struct
	{
		double	a;
		double	b;
		double	c;
	};
	double		f[3];
}	t_3f;

typedef union s_6f
{
	struct
	{
		double	a;
		double	b;
		double	c;
		double	d;
		double	e;
		double	f;
	};
	double		t[6];
}	t_6f;

typedef struct s_ijkl
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
}	t_ijkl;

/* ************************************************************************** */
/*                                                                            */
/*   hsize   		 taille horizontale du canevas en pixels                  */
/*   vsize   		 taille verticale du canevas du canevas                   */
/*   field_of_view   angle qui décrit ce que la caméra peut voir              */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_camera
{
	double		hsize;
	double		vsize;
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
	double			cyl_min;
	double			cyl_max;
	int				cyl_closed;
	struct s_object	*prev;
	struct s_object	*next;
}	t_object;

typedef struct s_world
{
	t_object	*lst_object;
	t_light		light;
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
	t_3f					t;
	t_object				*object;
	struct s_intersection	*prev;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_t_and_object
{
	double					t;
	t_object				*object;
	struct s_t_and_object	*prev;
	struct s_t_and_object	*next;
}	t_to;

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

typedef struct s_data_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_mlx_img;

typedef struct s_mlx_win_img
{
	void			*mlx;
	void			*win;
	t_data_mlx_img	*data_img;
	int				win_widht;
	int				win_height;
}	t_mwi;

typedef struct s_parsed_scene	t_parsed_scene;
typedef struct s_all_data
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;
	t_dk			*data_key;
	int				gen_img;
	t_object		*list_object;
	t_parsed_scene	*parsed_scene;
}	t_all_data;

typedef struct s_data_thread
{
	t_all_data		*all_data;
	t_camera		camera;
	t_world			*world;
	int				id_thread;
	t_bgra			stock_img[HEIGHT][WIDTH];
	pthread_mutex_t	mutex_print;
}	t_dt;

typedef struct s_data_main_exec_thread
{
	t_dt	*dt;
	t_ray	r;
	t_tuple	color;
	size_t	x;
	size_t	y;
}	t_dmet;

#endif
