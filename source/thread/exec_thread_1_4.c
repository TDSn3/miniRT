/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_thread_1_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:28 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 14:20:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_thread1(void *data)
{
	t_dmet	dmet;

	printf("%sThread 1 created%s\n", COLOR_RED, COLOR_RESET);
	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 0)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread2(void *data)
{
	t_dmet	dmet;

	printf("%sThread 2 created%s\n", COLOR_RED, COLOR_RESET);
	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 1)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread3(void *data)
{
	t_dmet	dmet;

	printf("%sThread 3 created%s\n", COLOR_RED, COLOR_RESET);
	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 2)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread4(void *data)
{
	t_dmet	dmet;

	printf("%sThread 4 created%s\n", COLOR_RED, COLOR_RESET);
	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 3)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}
