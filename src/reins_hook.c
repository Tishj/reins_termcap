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

void	reins_hook_run(t_hook *hook)
{
	if (hook->function)
		hook->function(hook->param);
}

int	reins_hook(t_reins *reins, char *keycode, t_hookf func, void *param)
{
	t_key	*key;

	if (!reins)
		return (0);
//	print_keycode_formatted(keycode, 6);
	key = trie_find_str(reins->keys, keycode);
	if (!key)
		return (0);
	key->hook.function = func;
	key->hook.param = param;
	return (1);
}
