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
	char	keycode[MAX_KEY_SIZE];
	t_node	**node;

	if (!reins || !create_keycode(raw_key, keycode))
		return (0);
//	print_keycode_formatted(keycode, 6);
	node = bstree_find(&reins->keys, keycode, util_strnlen(keycode, 6), NULL);
	if (!*node)
		return (0);
	key = (*node)->val;
	key->hook.function = f;
	key->hook.param = param;
	return (1);
}
