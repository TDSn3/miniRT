/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:43:34 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 19:19:15 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

// static void	exec_all_thread_main(t_dt *dt, pthread_t *t, int i, int *err);
// static int	exec_all_thread(t_dt *dt);
// static int	return_err(void);

void	render(t_all_data *all_data, t_camera camera, t_world *world)
{
	size_t			x;
	size_t			y;
	unsigned int	*pixel;

	pixel = (unsigned int *)all_data->mwi->addr;
	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			*pixel++ = convert_to_255(
					color_at(world, ray_for_pixel(camera, x, y))).bgra;
		}
	}
}

// static int	exec_all_thread(t_dt *dt)
// {
// 	pthread_t	t[12];
// 	int			err;
// 	int			i;

// 	i = 0;
// 	while (i < 12)
// 	{
// 		exec_all_thread_main(dt, &t[i], i, &err);
// 		if (err)
// 			return (return_err());
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 12)
// 	{
// 		printf("%sthread %d%s\n", COLOR_BOLD_RED, i, COLOR_RESET);
// 		pthread_join(t[i++], NULL);
// 	}
// 	return (0);
// }

// static void	exec_all_thread_main(t_dt *dt, pthread_t *t, int i, int *err)
// {
// 	if (i % 12 == 0)
// 		*err = pthread_create(t, NULL, exec_thread1, (void *) dt);
// 	else if (i % 12 == 1)
// 		*err = pthread_create(t, NULL, exec_thread2, (void *) dt);
// 	else if (i % 12 == 2)
// 		*err = pthread_create(t, NULL, exec_thread3, (void *) dt);
// 	else if (i % 12 == 3)
// 		*err = pthread_create(t, NULL, exec_thread4, (void *) dt);
// 	else if (i % 12 == 4)
// 		*err = pthread_create(t, NULL, exec_thread5, (void *) dt);
// 	else if (i % 12 == 5)
// 		*err = pthread_create(t, NULL, exec_thread6, (void *) dt);
// 	else if (i % 12 == 6)
// 		*err = pthread_create(t, NULL, exec_thread7, (void *) dt);
// 	else if (i % 12 == 7)
// 		*err = pthread_create(t, NULL, exec_thread8, (void *) dt);
// 	else if (i % 12 == 8)
// 		*err = pthread_create(t, NULL, exec_thread9, (void *) dt);
// 	else if (i % 12 == 9)
// 		*err = pthread_create(t, NULL, exec_thread10, (void *) dt);
// 	else if (i % 12 == 10)
// 		*err = pthread_create(t, NULL, exec_thread11, (void *) dt);
// 	else
// 		*err = pthread_create(t, NULL, exec_thread12, (void *) dt);
// }

// static int	return_err(void)
// {
// 	printf("Error : thread no createdn\n");
// 	return (1);
// }
