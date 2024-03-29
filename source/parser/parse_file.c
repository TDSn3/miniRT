/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:35 by rcatini           #+#    #+#             */
/*   Updated: 2023/03/25 18:45:15 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

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
	if (tokens[0] == NULL || tokens[0][0] == '#')
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
	size_t	filename_len;
	int		fd;
	char	*line;
	char	*error_msg;

	filename_len = ft_strlen(filename);
	if (filename_len < 4 || ft_strncmp(filename + filename_len - 3, ".rt", 4))
		return (printf("Error\nInvalid file extension\n"), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s\n", strerror(errno)));
	line = get_next_line(fd);
	while (line)
	{
		error_msg = parse_line(line, scene);
		if (error_msg)
		{
			printf("Error\n%s:\t%s\n", error_msg, line);
			return (close(fd), free(line), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (validate_scene(scene));
}
