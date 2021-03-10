/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:43:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:51:01 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdio.h>
#include <stdlib.h>

int	reins_hook(t_reins *reins, char *raw_key, void (*f)(), void *param)
{
	t_key	*key;
	ssize_t	index;
	char	keycode[6];

	if (!reins || !create_keycode(raw_key, keycode))
		return (0);
	index = find_key(reins, keycode, 6);
	if (index == -1)
		return (0);
	key = vec_getref(&reins->keys, index);
	if (!key)
		return (0);
	key->hook.function = f;
	key->hook.param = param;
	return (1);
}
