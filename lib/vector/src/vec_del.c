/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:12:59 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/05 20:26:49 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_del(t_vec* vec, size_t index)
{
	if (index + 1 >= vec->index)
		return (1);
	while (index < vec->index)
		vec->store[index] = vec->store[index + 1];
	vec->index--;
	return (1);
}
