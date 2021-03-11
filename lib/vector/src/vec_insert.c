/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_insert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 19:24:41 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 20:34:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"

int	vec_insert(t_vec *vec, void *buffer, size_t index, size_t n)
{
	if (index >= vec->size)
		return (vec_add(vec, buffer, n));
	if (!vec_realloc(vec, n))
		return (0);
	util_memmove(vec->store + ((index + n) * vec->type_size),
		vec->store + (index * vec->type_size),
		(vec->size - index) * vec->type_size);
	util_memcpy(vec->store + (index * vec->type_size), buffer, vec->type_size * n);
	vec->size += n;
	return (1);
}
