/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:21:09 by rcatini           #+#    #+#             */
/*   Updated: 2022/05/02 14:21:19 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*start_next_word(char **begin_word, char c, char **end_word)
{
	while (**begin_word && **begin_word != c)
		(*begin_word)++;
	*end_word = *begin_word;
	while (**begin_word && **begin_word == c)
		(*begin_word)++;
	return (*begin_word);
}

static char	**cleanup_tab(char **tab)
{
	while (*tab)
		free(*tab);
	free(tab);
	return (NULL);
}

static char	**create_tab(int n_words, char ***tab)
{
	*tab = malloc((n_words + 1) * sizeof(**tab));
	if (!*tab)
		return (NULL);
	(*tab)[n_words] = NULL;
	return (*tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n_words;
	int		i;
	char	*pos;
	char	*tmp;

	while (*s && *s == c)
		s++;
	n_words = *s != 0;
	pos = (char *)s;
	while (*start_next_word(&pos, c, &tmp))
		n_words++;
	if (!create_tab(n_words, &result))
		return (NULL);
	i = -1;
	while (++i < n_words)
	{
		pos = (char *)s;
		start_next_word((char **)&s, c, &tmp);
		result[i] = ft_substr(pos, 0, tmp - pos);
		if (!result[i])
			return (cleanup_tab(result));
	}
	return (result);
}
