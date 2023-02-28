/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_globals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:39 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 14:40:55 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

char	*parse_ambient(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC, OCT_3};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}

char	*parse_camera(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, INT};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}

char	*parse_light(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC, OCT_3};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}
