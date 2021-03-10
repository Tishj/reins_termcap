/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:21:11 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 12:02:10 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

t_key	*get_key(t_reins *reins, char *keycode, size_t size)
{
	ssize_t	index;

	index = find_key(reins, keycode, size);
	if (index == -1)
		return (NULL);
	return (vec_getref(&reins->keys, (size_t)index));
}
