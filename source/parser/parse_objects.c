/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:08:53 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 14:41:23 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:43 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/19 19:10:12 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

char	*parse_sphere(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC, OCT_3};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}

char	*parse_plane(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, OCT_3};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}

char	*parse_cylinder(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, DEC, DEC, OCT_3};

	(void)scene;
	(void)tokens;
	(void)syntax;
	return (0);
}
