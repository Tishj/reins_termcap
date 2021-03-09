/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:43:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 11:05:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

#include <stdio.h>
#include <stdlib.h>

int		reigns_hook(t_reigns* reigns, char keycode[6], void (*f)(), void* param)
{
	t_key	*key;
	ssize_t	index;

	if (!reigns)
		return (0);
	index = find_key(reigns, keycode, 6);
	if (index == -1)
		return (0);
	key = vec_getref(&reigns->keys, index);
	if (!key)
		return (0);
	key->hook.function = f;
	key->hook.param = param;
	return (1);
}
