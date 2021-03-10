/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/10 14:33:03 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_int.h"
#include <stdlib.h>

int	vec_add(t_vec *vector, void *buffer)
{
	if (!vec_realloc(vector))
		return (0);
	util_memcpy(vector->store + (vector->size * vector->type_size),
		buffer, vector->type_size);
	vector->size++;
	return (1);
}
