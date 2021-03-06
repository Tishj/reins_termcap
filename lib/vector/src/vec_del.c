/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:12:59 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 12:29:22 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_del(t_vec* vec, size_t index)
{
	size_t i;

	if (index >= vec->index)
		return (1);
	index++;
	while (index < vec->index)
	{
		i = 0;
		while (i < vec->type_size)
		{
			vec->store[(index * vec->type_size) + i] = 
				vec->store[((index + 1) * vec->type_size) + i];
			i++;
		}
		index++;
	}
	vec->store[vec->index] = '\0';
	vec->index--;
	return (1);
}
