/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_realloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 19:26:41 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 19:51:13 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <vector_int.h>
#include <stdlib.h>

int		vec_realloc(t_vec* vector)
{
	char	*data;

	if (vector->index < vector->capacity)
		return (1);
	data = malloc(vector->type_size * vector->capacity);
	if (!data)
		return (0);
	util_memcpy(data, vector->store, vector->type_size * vector->index);
	free(vector->store);
	vector->store = data;
	return (1);
}
