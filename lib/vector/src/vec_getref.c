/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_getref.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/06 11:53:39 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	*vec_getref(t_vec *vector, size_t index)
{
	if (index >= vector->capacity)
		return (NULL);
	return (&vector->store[index * vector->type_size]);
}
