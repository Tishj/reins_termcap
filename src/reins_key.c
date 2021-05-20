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
int	reins_key(t_reins *reins, char *keycode, t_keyf function)
{
	t_key	*key;

	if (!reins)
		return (0);
	key = new_key(keycode, function);
	if (!key || !trie_insert(&reins->keys, keycode, key))
	{
		free(key);
		return (0);
	}
	return (1);
}
