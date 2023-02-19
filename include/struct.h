/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:06:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 16:12:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* ************************************************************************** */
/*                                                                            */
/*   big-endian      x y z w                                                  */
/*   little-endian   w z y x                                                  */
/*                                                                            */
/*   w = 1   point                                                            */
/*   w = 0   vector                                                           */
/*                                                                            */
/* ************************************************************************** */
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

typedef struct s_matrix
{
	float	**tab;
	size_t	x_size;
	size_t	y_size;
}	t_matrix;

typedef union s_argb
{
	struct
	{
		int8_t	a;
		int8_t	r;
		int8_t	g;
		int8_t	b;
	};
	int32_t		argb;
}	t_argb;

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