/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:37:38 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 15:50:07 by rcatini          ###   ########.fr       */
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

typedef char	*(*t_parse)(t_scene *, char **);

int		parse_scene(char *filename, t_scene *scene);
char	*parse_sphere(t_scene *scene, char **tokens);
char	*parse_plane(t_scene *scene, char **tokens);
char	*parse_cylinder(t_scene *scene, char **tokens);
char	*parse_ambient(t_scene *scene, char **tokens);
char	*parse_camera(t_scene *scene, char **tokens);
char	*parse_light(t_scene *scene, char **tokens);
void	free_tokens(char **tokens);
void	clean_line(char *line);
int		count_tokens(char **tokens);
int		parse_items(int n, char **tokens, const t_parameter *syntax,
			void **params);

#endif