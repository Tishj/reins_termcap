/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:12:59 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/13 17:19:50 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"

int	vec_del(t_vec *vec, size_t index, size_t n)
{
	if (index + n >= vec->size)
		return (1);
	util_memmove(vec->store + (index * vec->type_size),
		vec->store + ((index + n) * vec->type_size),
		vec->type_size * (vec->size - index));
	vec->size -= n;
	return (1);
}
