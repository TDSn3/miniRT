/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:44:40 by roberto           #+#    #+#             */
/*   Updated: 2023/03/10 23:08:43 by rcatini          ###   ########.fr       */
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

t_object	*object_lst_new(t_type type, t_parsed_ambient const *ambient)
{
	t_object	*obj;

	obj = malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	*obj = (t_object){0};
	obj->type = type;
	identity_matrix(4, (double *)&obj->transform);
	inverse_matrix4(&obj->transform, &obj->inverse);
	obj->material.ambient = ambient->intensity;
	obj->material.a_color = (t_tuple){{ambient->color.b, ambient->color.g,
		ambient->color.r, 0}};
	obj->material.diffuse = 0.9;
	obj->material.specular = 0.9;
	obj->material.shininess = 200;
	return (obj);
}
