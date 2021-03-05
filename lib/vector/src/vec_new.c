/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/03 20:49:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/03 13:36:02 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

int		vec_new(t_vec *vector, size_t type_size)
{
	vector->capacity = 4;
	vector->index = 0;
	vector->type_size = type_size;
	vector->store = malloc(sizeof(type_size) * (vector->capacity));
	if (!vector->store)
		return (0);
	return (1);
}
