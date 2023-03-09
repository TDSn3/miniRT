/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:44:40 by roberto           #+#    #+#             */
/*   Updated: 2023/03/08 23:05:20 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	object_lst_clear(t_object **lst)
{
	t_object	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

t_object	*object_lst_new(t_type type, t_ambient const *ambient)
{
	t_object	*obj;

	obj = malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	*obj = (t_object){0};
	obj->type = type;
	obj->position = (t_tuple){{0, 0, 0, 1}};
	give_identity_matrix4(&obj->transform);
	give_identity_matrix4(&obj->inverse);
	obj->material.color = (t_tuple){{1, 0.2, 1, 0}};
	obj->material.ambient = ambient->intensity;
	obj->material.a_color = ambient->color;
	obj->material.diffuse = 0.9;
	obj->material.specular = 0.9;
	obj->material.shininess = 200;
	return (obj);
}
