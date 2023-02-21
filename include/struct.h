/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:06:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 22:28:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef union s_tuple
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
	float		tuple[4];
}	t_tuple;

typedef union s_ray
{
	struct
	{
		union
		{
			struct
			{
				float	x;
				float	y;
				float	z;
				float	w;
			};
			float		tab[4];
			t_tuple		vector;
		};
		union
		{
			struct
			{
				float	x2;
				float	y2;
				float	z2;
				float	w2;
			};
			float		tab2[4];
			t_tuple		point;
		};
	};
	float	ray_tab[8];
}	t_ray;

typedef union s_light
{
	struct
	{
		union
		{
			struct
			{
				float	x;
				float	y;
				float	z;
				float	w;
			};
			float		tab[4];
			t_tuple		intensity;
		};
		union
		{
			struct
			{
				float	x2;
				float	y2;
				float	z2;
				float	w2;
			};
			float		tab2[4];
			t_tuple		position;
		};
	};
	float	light_tab[8];
}	t_light;

typedef struct s_material
{
	t_tuple	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef union s_bgra
{
	struct
	{
		int8_t	b;
		int8_t	g;
		int8_t	r;
		int8_t	a;
	};
	int32_t		bgra;
}	t_bgra;

typedef union s_3f
{
	struct
	{
		float	a;
		float	b;
		float	c;
	};
	float		f[3];
}	t_3f;

typedef union s_6f
{
	struct
	{
		float	a;
		float	b;
		float	c;
		float	d;
		float	e;
		float	f;
	};
	float		t[6];
}	t_6f;

typedef struct s_matrix
{
	float	**tab;
	size_t	x_size;
	size_t	y_size;
}	t_matrix;

typedef struct s_ijkl
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
}	t_ijkl;

typedef enum e_type
{
	SPHERE,
}	t_type;

/* ************************************************************************** */
/*                                                                            */
/*   Par défaut   transform = new_identity_matrix()                           */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_object
{
	unsigned int	id;
	t_type			type;
	t_tuple			position;
	t_matrix		*transform;
	t_material		material;
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
	t_3f					t;
	t_object				object;
	struct s_intersection	*prev;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_t_and_object
{
	float		t;
	t_object	object;
}	t_to;

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

typedef struct s_all_data
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;
}	t_all_data;

#endif