/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:57:15 by tda-silv         ###   ########.fr       */
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

# define EPSILON 0.00001

/* ************************************************************************** */
/*                                                                            */
/*   w = 1   point                                                            */
/*   w = 0   vector                                                          */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef union s_argb
{
	struct
	{
		int8_t	a;
		int8_t	r;
		int8_t	g;
		int8_t	b;
	};
	int32_t		rgba;
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

void	my_mlx_pixel_put(t_all_data *all_data, int x, int y, int color);
void	init_point(t_tuple *tuple, float x, float y, float z);
void	init_vector(t_tuple *tuple, float x, float y, float z);
void	t_tuple_plus(t_tuple *left, t_tuple *right);
void	t_tuple_minus(t_tuple *left, t_tuple *right);
void	t_tuple_nega(t_tuple *tuple);
void	t_tuple_multi_scal(t_tuple *tuple, float a);
void	t_tuple_div_scal(t_tuple *tuple, float a);
float	magnitude_vector(t_tuple *tuple);
void	normalization_vector(t_tuple *tuple);

#endif
