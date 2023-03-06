/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:58:52 by rcatini           #+#    #+#             */
/*   Updated: 2022/10/01 13:00:14 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#define BUFFER_SIZE 32

char	*ft_strnjoin(char **s1, char *s2, ssize_t *count)
{
	char	*result;

	if (!*s1)
	{
		*s1 = ft_strdup(s2);
		if (!*s1)
		{
			*count = -1;
			return (NULL);
		}
		return (*s1);
	}
	result = malloc(ft_strlen(*s1) + *count + 1);
	if (!result)
	{
		*count = -1;
		return (NULL);
	}
	ft_strcpy(result, *s1);
	ft_strcpy(result + ft_strlen(result), s2);
	free(*s1);
	*s1 = result;
	return (result);
}

char	*ft_trim_line(char *line, char *buf)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (!newline)
	{
		*buf = '\0';
		return (NULL);
	}
	ft_strcpy(buf, newline + 1);
	*(newline + 1) = '\0';
	return (newline);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	ssize_t			count;
	char			*line;

	line = NULL;
	if (!*buf)
		count = read(fd, buf, BUFFER_SIZE);
	else
		count = ft_strlen(buf);
	while (count > 0)
	{
		buf[count] = '\0';
		if (!ft_strnjoin(&line, buf, &count))
			break ;
		if (ft_trim_line(line, buf))
			break ;
		count = read(fd, buf, BUFFER_SIZE);
	}
	if (count < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
