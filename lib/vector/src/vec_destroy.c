/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/10 14:33:01 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

int		vec_destroy(t_vec *vector, void (*del)(void *))
{
	if (del)
	{
		for (size_t i = 0; i < vector->size; i++)
			del(vec_getref(vector, i));
	}
	free(vector->store);
	vector->capacity = 0;
	vector->size = 0;
	vector->type_size = 0;
	vector->store = NULL;
	return (0);
}
