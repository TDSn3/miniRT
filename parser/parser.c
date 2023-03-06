/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:56:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 06:18:47 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"
#include "libft.h"

t_3f	parse_vec3(char *item)
{
	t_3f	vec;
	char	**tokens;

	vec = (t_3f){.a = NAN, .b = NAN, .c = NAN};
	tokens = ft_split(item, ',');
	if (!tokens)
		return (vec);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), vec);
	vec.a = ft_atod(tokens[0]);
	vec.b = ft_atod(tokens[1]);
	vec.c = ft_atod(tokens[2]);
	return (free_tokens(tokens), vec);
}

t_bgra	parse_color(char *item)
{
	t_bgra	color;
	char	**tokens;

	color = (t_bgra){.a = 255};
	tokens = ft_split(item, ',');
	if (!tokens)
		return (color);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), color);
	color.r = ft_atoi(tokens[0]);
	color.g = ft_atoi(tokens[1]);
	color.b = ft_atoi(tokens[2]);
	color.a = 0;
	return (free_tokens(tokens), color);
}

int	is_invalid(const t_parameter type, void *param)
{
	if (type == DEC)
		return (isnan(*(double *)param));
	else if (type == DEC_3)
		return (isnan(((t_3f *)param)->a) || isnan(((t_3f *)param)->b)
			|| isnan(((t_3f *)param)->c));
	else if (type == COLOR)
		return (((t_bgra *)param)->a == 255);
	return (1);
}

int	parse_items(int n, char **tokens, const t_parameter *syntax, void **params)
{
	int	i;

	if (count_tokens(tokens) != n)
		return (1);
	i = -1;
	while (++i < n)
	{
		if (syntax[i] == DEC)
			*(double *)params[i] = ft_atod(tokens[i]);
		else if (syntax[i] == DEC_3)
			*(t_3f *)params[i] = parse_vec3(tokens[i]);
		else if (syntax[i] == COLOR)
			*(t_bgra *)params[i] = parse_color(tokens[i]);
		else
			return (1);
		if (is_invalid(syntax[i], params[i]))
			return (1);
	}
	if (tokens[i])
		return (1);
	return (0);
}
