/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:12:59 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 20:27:40 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"

int	vec_del(t_vec* vec, size_t index)
{
	if (index >= vec->index)
		return (1);
	util_memmove(vec->store + (index * vec->type_size),
		vec->store + ((index + 1) * vec->type_size),
		vec->type_size * vec->index);
	vec->index--;
	return (1);
}
