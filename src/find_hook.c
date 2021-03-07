/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_hook.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:22:14 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 23:13:44 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

ssize_t	find_hook(t_reigns* reigns, char *keycode, size_t size)
{
	size_t	i;
	t_hook	*tmp;

	i = 0;
	while (i < reigns->hooks.index)
	{
		tmp = vec_getref(&reigns->hooks, i);
		if (!util_strncmp(tmp->buf, keycode, size))
			return (i);
		i++;
	}
	return (-1);
}
