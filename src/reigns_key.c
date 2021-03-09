/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_key.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 23:41:18 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 11:11:31 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

//add or replace a function to handle a certain keycode
int		reigns_key(t_reigns* reigns, char keycode[6], t_keyf func)
{
	ssize_t	index;
	t_key	*key;

	if (!reigns)
		return (0);
	index = find_key(reigns, keycode, 6);
	if (index == -1)
		return (vec_add(&reigns->keys, new_key(keycode, func)));
	key = get_key(reigns, keycode, index);
	if (!key)
		return (0);
	util_memcpy(key->buf, keycode, 6);
	key->size = util_strnlen(key->buf, 6);
	key->function = func;
	return (1);
}
