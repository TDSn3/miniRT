/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:02:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 17:43:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	*ft_calloc(size_t nmemb, size_t size);
static void	ft_bzero(void *s, size_t n);

/* ************************************************************************** */
/*                                                                            */
/*   Initialise une matrice en allouant de l'espace en mémoire à l'aide       */
/*   de la fonction ft_calloc, initialise toutes les valeurs à 0 avec         */
/*   ft_bzero, et libère toute la mémoire allouée en cas d'erreur avec        */
/*   la fonction free_function_all.                                           */
/*                                                                            */
/*   La fonction init_matrix prend en entrée t_matrix, la taille de           */
/*   la matrice dans les dimensions x et y, et alloue de la mémoire pour      */
/*   stocker les valeurs de la matrice. Elle retourne 0 si l'initialisation   */
/*   a réussi et 1 si elle a échoué.                                          */
/*                                                                            */
/* ************************************************************************** */
int	init_matrix(t_matrix *a, size_t x_size, size_t y_size)
{
	size_t	i;

	i = 0;
	a->tab = NULL;
	a->x_size = x_size;
	a->y_size = 0;
	a->tab = ft_calloc(x_size, sizeof(float *));
	if (!a->tab)
		return (1);
	while (i < x_size)
	{
		a->tab[i] = ft_calloc(y_size, sizeof(float));
		if (!a->tab[i])
			return (free_matrix(a));
		a->y_size++;
		i++;
	}
	return (0);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
