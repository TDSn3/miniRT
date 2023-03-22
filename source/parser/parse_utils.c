/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:47:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/16 14:17:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

void	clean_line(char *line)
{
	while (*line)
	{
		if (*line >= '\t' && *line <= '\r')
			*line = ' ';
		line++;
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

void	free_objects(t_parsed_object *objects)
{
	t_parsed_object	*next;

	while (objects)
	{
		next = objects->next;
		free(objects);
		objects = next;
	}
}
