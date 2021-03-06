/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_insert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 19:24:41 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 20:23:17 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"

int	vec_insert(t_vec* vec, void* buffer, size_t index)
{
	if (index >= vec->index)
		return (vec_add(vec, buffer));
	if (!vec_realloc(vec))
		return (0);
	util_memmove(vec->store + ((index + 1) * vec->type_size), 
		vec->store + (index * vec->type_size),
		(vec->index - index) * vec->type_size);
	util_memcpy(vec->store + (index * vec->type_size), buffer, vec->type_size);
	vec->index++;
	return (1);
}
