/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_realloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 19:26:41 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 20:31:34 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <vector_int.h>
#include <stdlib.h>

int	vec_realloc(t_vec *vector, size_t n)
{
	char	*data;

	if (!n)
		return (0);
	if (vector->size + n < vector->capacity)
		return (1);
	while (vector->size + n > vector->capacity)
		vector->capacity *= 2;
	data = malloc(vector->type_size * vector->capacity);
	if (!data)
		return (0);
	util_memcpy(data, vector->store, vector->type_size * vector->size);
	free(vector->store);
	vector->store = data;
	return (1);
}
