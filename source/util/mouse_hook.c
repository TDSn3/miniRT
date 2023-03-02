/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:44:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 18:42:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	mouse_hook(int mousecode, int x, int y, t_all_data *d)
{
	printf("%s%d\tx : %d\t\ty : %d%s\n",
		COLOR_ID_WHITE, mousecode, x, y, COLOR_RESET);
	return (0);
}
