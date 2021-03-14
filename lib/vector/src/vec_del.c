/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:12:59 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/14 16:36:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"

/*
** Deletes n bytes starting at index
*/
int	vec_del(t_vec *vec, size_t index, size_t n)
{
	if (index + n >= vec->size)
		n = vec->size - index;
	if (vec->size - (index + n) >= n)
	{
		util_memmove(vec->store + (index * vec->type_size),
			vec->store + ((index + n) * vec->type_size),
			vec->type_size * (vec->size - index));
	}
	vec->size -= n;
	return (1);
}
