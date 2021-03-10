/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_getref.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/10 14:33:02 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	*vec_getref(t_vec *vector, size_t index)
{
	if (index >= vector->capacity || index >= vector->size)
		return (NULL);
	return (&vector->store[index * vector->type_size]);
}
