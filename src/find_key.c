/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_key.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:22:14 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 14:33:04 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

ssize_t	find_key(t_reins* reins, char *keycode, size_t size)
{
	size_t	i;
	t_key	*tmp;

	i = 0;
	while (i < reins->keys.size)
	{
		tmp = vec_getref(&reins->keys, i);
		if (!util_strncmp(tmp->buf, keycode, size))
			return (i);
		i++;
	}
	return (-1);
}
