/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:37:38 by roberto           #+#    #+#             */
/*   Updated: 2023/03/08 20:33:59 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

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

#endif