/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_key.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 23:41:18 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:19:54 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

/*
**	Add or replace a function to handle a certain keycode
*/
int	reins_key(t_reins *reins, char *raw_key, t_keyf func)
{
	char	keycode[MAX_KEY_SIZE];
	t_key	*key;
	size_t	len;

	if (!reins || !create_keycode(raw_key, keycode))
		return (0);
//	print_keycode_formatted(keycode, 6);
	len = util_strnlen(keycode, 6);
	key = new_key(keycode, func);
	if (!key || !bstree_assign(&reins->keys, keycode, len, key))
		return (0);
	return (1);
}

// int	reins_key(t_reins *reins, int key, bool csi, char modifier)
// {
// 	char	*keycode;

// }
