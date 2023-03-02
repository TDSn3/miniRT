/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created 2023/02/24 20:21:09 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 14:00:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

// void	render(t_all_data *all_data, t_camera camera, t_world *world)
// {
// 	t_ray	r;
// 	t_tuple	color;
// 	size_t	x;
// 	size_t	y;
//
// 	x = 0;
// 	y = 0;
// 	while (y < camera.vsize)
// 	{
// 		while (x < camera.hsize)
// 		{
// 			r = ray_for_pixel(camera, x, y);
// 			color = color_at(world, r);
// 			my_mlx_pixel_put(all_data, x - camera.hsize / 2,
//				y - camera.vsize / 2, convert_to_255(color).bgra);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
//
//   TEST THREAD

int	return_err(void)
{
	printf("Error : thread no createdn");
	return (1);
}

int	exec_all_thread(t_dt *dt)
{
	pthread_t	t[12];
	int			err;
	int			i;

	i = 0;
	while (i < 12)
	{
		if (i % 12 == 0)
			err = pthread_create(&t[i], NULL, exec_thread1, (void *) dt);
		else if (i % 12 == 1)
			err = pthread_create(&t[i], NULL, exec_thread2, (void *) dt);
		else if (i % 12 == 2)
			err = pthread_create(&t[i], NULL, exec_thread3, (void *) dt);
		else if (i % 12 == 3)
			err = pthread_create(&t[i], NULL, exec_thread4, (void *) dt);
		else if (i % 12 == 4)
			err = pthread_create(&t[i], NULL, exec_thread5, (void *) dt);
		else if (i % 12 == 5)
			err = pthread_create(&t[i], NULL, exec_thread6, (void *) dt);
		else if (i % 12 == 6)
			err = pthread_create(&t[i], NULL, exec_thread7, (void *) dt);
		else if (i % 12 == 7)
			err = pthread_create(&t[i], NULL, exec_thread8, (void *) dt);
		else if (i % 12 == 8)
			err = pthread_create(&t[i], NULL, exec_thread9, (void *) dt);
		else if (i % 12 == 9)
			err = pthread_create(&t[i], NULL, exec_thread10, (void *) dt);
		else if (i % 12 == 10)
			err = pthread_create(&t[i], NULL, exec_thread11, (void *) dt);
		else
			err = pthread_create(&t[i], NULL, exec_thread12, (void *) dt);
		if (err)
			return (return_err());
		i++;
	}
	i = 0;
	while (i < 12)
		pthread_join(t[i++], NULL);
	return (0);
}

void	render(t_all_data *all_data, t_camera camera, t_world *world)
{
	t_dt	dt;

	dt.all_data = all_data;
	dt.camera = camera;
	dt.world = world;
	exec_all_thread(&dt);
}
