/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 11:38:54 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 13:38:21 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

int	init_keys(t_reigns* reigns)
{
	char				tmp[6];
	static const t_keyf	functions[] = {
		key_eof,
		key_del,
		key_right,
		key_left,
		key_up,
		key_down,
		key_newline,
		key_regular,
		NULL
	};
	static const char *keycodes[] = {
		KEY_CNTRL_D,
		KEY_DEL,
		KEY_ESC "[" KEY_RIGHT,
		KEY_ESC "[" KEY_LEFT,
		KEY_ESC "[" KEY_UP,
		KEY_ESC "[" KEY_DOWN,
		KEY_NEWLINE,
		" "
	};

	if (!vec_new(&reigns->keys, sizeof(t_key)))
		return (0);
	for (size_t i = 0; functions[i]; i++)
	{
		if (functions[i] == key_regular)
		{
			util_memcpy(tmp, (void *)keycodes[i], 6);
			for (size_t j = 32; j <= 126; j++)
			{
				tmp[0] = (char)j;
				if (!reigns_key(reigns, tmp, functions[i]))
					return (0);
			}
		}
		else if (!reigns_key(reigns, (char *)keycodes[i], functions[i]))
			return (0);
	}
	return (1);
}
