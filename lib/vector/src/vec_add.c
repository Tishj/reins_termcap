/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/06 12:02:00 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static void	ft_memcpy(void *dst, void *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}

int		vec_add(t_vec *vector, void *buffer)
{
	char	*new_store;

	if (vector->index >= vector->capacity)
	{
		vector->capacity *= 2;
		new_store = malloc(vector->type_size * vector->capacity);
		if (!new_store)
			return (0);
		ft_memcpy(new_store, vector->store,
			(vector->type_size * vector->index));
		free(vector->store);
		vector->store = new_store;
	}
	ft_memcpy(&vector->store[vector->index * vector->type_size],
		buffer, vector->type_size);
	vector->index++;
	return (1);
}
