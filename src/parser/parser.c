/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:56:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/09 15:53:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>
#include <libft.h>

t_parsed_vector	parse_vec3(char *item)
{
	double					x;
	double					y;
	double					z;
	char					**tokens;
	const t_parsed_vector	invalid
		= (t_parsed_vector){.x = NAN, .y = NAN, .z = NAN};

	tokens = ft_split(item, ',');
	if (!tokens)
		return (invalid);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), invalid);
	x = ft_atod(tokens[0]);
	y = ft_atod(tokens[1]);
	z = ft_atod(tokens[2]);
	if (isnan(x) || isnan(y) || isnan(z))
		return (free_tokens(tokens), invalid);
	return (free_tokens(tokens), (t_parsed_vector){.x = x, .y = y, .z = z});
}

t_parsed_color	parse_color(char *item)
{
	char					**tokens;
	int						r;
	int						g;
	int						b;
	const t_parsed_color	invalid = (t_parsed_color){.a = 255};

	tokens = ft_split(item, ',');
	if (!tokens)
		return (invalid);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), invalid);
	r = ft_atouc(tokens[0]);
	g = ft_atouc(tokens[1]);
	b = ft_atouc(tokens[2]);
	if (r == -1 || g == -1 || b == -1)
		return (free_tokens(tokens), invalid);
	return (free_tokens(tokens),
		(t_parsed_color){.a = 0, .r = r, .g = g, .b = b});
}

int	is_invalid(const t_parameter type, void *param)
{
	if (type == DEC)
		return (isnan(*(double *)param));
	else if (type == DEC_3)
		return (isnan(((t_parsed_vector *)param)->x)
			|| isnan(((t_parsed_vector *)param)->y)
			|| isnan(((t_parsed_vector *)param)->z));
	else if (type == COLOR)
		return (((t_parsed_color *)param)->a == 255);
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
			*(t_parsed_vector *)params[i] = parse_vec3(tokens[i]);
		else if (syntax[i] == COLOR)
			*(t_parsed_color *)params[i] = parse_color(tokens[i]);
		else
			return (1);
		if (is_invalid(syntax[i], params[i]))
			return (1);
	}
	if (tokens[i])
		return (1);
	return (0);
}
