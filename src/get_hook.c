/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:21:11 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 23:48:55 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <stdio.h>

t_hook	*get_hook(t_reigns* reigns, char *keycode, size_t size)
{
	ssize_t	index;

	index = find_hook(reigns, keycode, size);
	if (index == -1)
		return (NULL);
	return (vec_getref(&reigns->hooks, (size_t)index));
}
