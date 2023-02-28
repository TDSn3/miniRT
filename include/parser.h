/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:37:38 by roberto           #+#    #+#             */
/*   Updated: 2023/02/28 14:37:30 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_parameter {
	DEC,
	DEC_3,
	OCT,
	OCT_3,
	INT,
	INT_3,
}	t_parameter;

int		parse_scene(char *filename, t_scene *scene);
char	*parse_sphere(t_scene *scene, char **tokens);
char	*parse_plane(t_scene *scene, char **tokens);
char	*parse_cylinder(t_scene *scene, char **tokens);
char	*parse_ambient(t_scene *scene, char **tokens);
char	*parse_camera(t_scene *scene, char **tokens);
char	*parse_light(t_scene *scene, char **tokens);

#endif