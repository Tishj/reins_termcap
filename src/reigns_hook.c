/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:43:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 00:26:01 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

#include <stdio.h>
#include <stdlib.h>

int		reigns_hook(t_reigns* reigns, char keycode[6], void (*f)(), void* param)
{
	t_hook	*hook;
	ssize_t	index;

	if (!reigns)
		return (0);
	if (!f)
		return (0);
	index = find_hook(reigns, keycode, 6);
	if (index == -1)
	{
		hook = new_hook(keycode, f, param);
		if (!hook || !vec_add(&reigns->hooks, hook))
			return (0);
		free(hook);
		return (1);
	}
	hook = vec_getref(&reigns->hooks, index);
	if (!hook)
		return (0);
	util_memcpy(hook->buf, keycode, 6);
	hook->function = f;
	hook->param = param;
	return (1);
}
