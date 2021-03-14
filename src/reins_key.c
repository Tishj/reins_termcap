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
	ssize_t	index;
	t_key	*key;
	char	keycode[MAX_KEY_SIZE];
	int		ret;

	if (!reins || !create_keycode(raw_key, keycode))
		return (0);
//	print_keycode_formatted(keycode, MAX_KEY_SIZE);
	index = find_key(reins, keycode, MAX_KEY_SIZE);
	if (index == -1)
	{
		key = new_key(keycode, func);
		if (!key)
			return (0);
		ret = vec_add(&reins->keys, key, 1);
		free(key);
		return (ret);
	}
	key = get_key(reins, keycode, index);
	if (!key)
		return (0);
	util_memcpy(key->buf, keycode, MAX_KEY_SIZE);
	key->size = util_strnlen(key->buf, MAX_KEY_SIZE);
	key->function = func;
	return (1);
}
