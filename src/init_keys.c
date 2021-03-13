/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 11:38:54 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/13 13:42:01 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

static const t_keyf	*functions_singleton(void)
{
	static const t_keyf	functions[] = {
		key_home,
		key_end,
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

	return (functions);
}

static const char	**keycodes_singleton(void)
{
	static const char	*keycodes[] = {
		KEY_ESC "[" KEY_HOME,
		KEY_ESC "[" KEY_END,
		KEY_CNTRL_D,
		KEY_DEL,
		KEY_ESC "[" KEY_RIGHT,
		KEY_ESC "[" KEY_LEFT,
		KEY_ESC "[" KEY_UP,
		KEY_ESC "[" KEY_DOWN,
		KEY_NEWLINE,
		" "
	};

	return (keycodes);
}

static int	regular_ascii_keys(t_reins *reins)
{
	char	buff[2];

	buff[0] = ' ';
	buff[1] = '\0';
	while (buff[0] <= 126)
	{
		if (!reins_key(reins, buff, key_regular))
			return (0);
		buff[0]++;
	}
	return (1);
}

int	init_keys(t_reins *reins)
{
	const t_keyf	*functions;
	const char		**keycodes;
	size_t			i;
	char			tmp[6];

	functions = functions_singleton();
	keycodes = keycodes_singleton();
	if (!vec_new(&reins->keys, sizeof(t_key)))
		return (0);
	i = 0;
	while (functions[i])
	{
		util_bzero(tmp, 6);
		if (functions[i] == key_regular && !regular_ascii_keys(reins))
			return (0);
		else if (!reins_key(reins, (char *)keycodes[i], functions[i]))
			return (0);
		i++;
	}
	return (1);
}
