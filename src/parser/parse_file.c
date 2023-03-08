/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:35 by rcatini           #+#    #+#             */
/*   Updated: 2023/03/08 03:30:38 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>
#include <libft.h>

char	*parse_line(char *line, t_parsed_scene *scene)
{
	const char		*types[] = {"A", "C", "L", "sp", "pl", "cy", NULL};
	const t_parse	parse[] = {parse_ambient, parse_camera, parse_light,
		parse_sphere, parse_plane, parse_cylinder};
	char			**tokens;
	int				i;

	clean_line(line);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return ("Memory allocation error");
	if (tokens[0] == NULL)
		return (free_tokens(tokens), NULL);
	i = -1;
	while (types[++i])
	{
		if (!ft_strncmp(tokens[0], types[i], ft_strlen(types[i]) + 1))
			return (parse[i](scene, tokens + 1));
	}
	return (free_tokens(tokens), "Unknown object");
}

int	validate_scene(t_parsed_scene *scene)
{
	if (!scene->light.initialized)
		return (printf("Error\nNo light source defined\n"), 1);
	if (!scene->camera.initialized)
		return (printf("Error\nNo camera defined\n"), 1);
	if (!scene->ambient.initialized)
		return (printf("Error\nNo ambient light defined\n"), 1);
	return (0);
}

int	parse_scene(char *filename, t_parsed_scene *scene)
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
	return (validate_scene(scene));
}
