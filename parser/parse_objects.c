/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:43:21 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 04:23:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

char	*parse_sphere(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC, COLOR};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (free_tokens(--tokens), NULL);
}

char	*parse_plane(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, COLOR};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (free_tokens(--tokens), NULL);
}

char	*parse_cylinder(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, DEC, DEC, COLOR};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (free_tokens(--tokens), NULL);
}
