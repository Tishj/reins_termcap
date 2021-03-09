/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_key.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:22:14 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:51:12 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

ssize_t	find_key(t_reigns* reigns, char *keycode, size_t size)
{
	size_t	i;
	t_key	*tmp;

	i = 0;
	while (i < reigns->keys.index)
	{
		tmp = vec_getref(&reigns->keys, i);
		if (!util_strncmp(tmp->buf, keycode, size))
			return (i);
		i++;
	}
	return (-1);
}
