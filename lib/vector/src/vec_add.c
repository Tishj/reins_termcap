/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/11 20:34:43 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"
#include <stdlib.h>

int	vec_add(t_vec *vector, void *buffer, size_t n)
{
	if (!vec_realloc(vector, n))
		return (0);
	util_memcpy(vector->store + (vector->size * vector->type_size),
		buffer, vector->type_size * n);
	vector->size += n;
	return (1);
}
