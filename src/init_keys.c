/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 11:38:54 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:57:52 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

static int	populate_keys_vector(t_reigns* reigns,
		const t_keyf* functions,
		const char **keycodes)
{
	size_t	i;
	size_t	j;
	char	tmp[6];

	if (!vec_new(&reigns->keys, sizeof(t_key)))
		return (0);
	i = 0;
	while (functions[i])
	{
		util_bzero(tmp, 6);
		if (functions[i] == key_regular)
		{
			j = 32;
			util_strncpy(tmp, (char *)keycodes[i], 6);
			while (j <= 126)
			{
				tmp[0] = (char)j;
				if (!reigns_key(reigns, tmp, functions[i]))
					return (0);
				j++;
			}
		}
		else if (!reigns_key(reigns, (char *)keycodes[i], functions[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_keys(t_reigns* reigns)
{
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
	return (populate_keys_vector(reigns, functions, keycodes));
}
