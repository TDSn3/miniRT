/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:35 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 15:22:35 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

void	clean_line(char *line)
{
	while (*line)
	{
		if (*line >= '\t' && *line <= '\r')
			*line = ' ';
		line++;
	}
}

char	*parse_line(char *line, t_scene *scene)
{
	char const	*const types[] = {"A", "C", "L", "sp", "pl", "cy", NULL};
	char		*(*const parse[])(t_scene *, char **) = {parse_ambient,
	 	parse_camera, parse_light, parse_sphere, parse_plane, parse_cylinder};
	char		**tokens;
	int			i;

	clean_line(line);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return ("Memory allocation error");
	if (tokens[0] == NULL)
		return (NULL);
	i = -1;
	while (types[++i])
	{
		if (!ft_strncmp(tokens[0], types[i], ft_strlen(types[i]) + 1))
			return (parse[i](scene, tokens + 1));
	}
	return ("Unknown object");
}

int	parse_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*error_msg;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s\n", strerror(errno)));
	line = get_next_line(fd);
	while (line)
	{
		error_msg = parse_line(line, scene);
		if (error_msg)
		{
			close(fd);
			printf("Error\n%s:\t%s", error_msg, line);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
