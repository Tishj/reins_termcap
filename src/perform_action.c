/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perform_action.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:25:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 11:54:43 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

t_key	*get_action(t_reigns* reigns, char *buf, size_t* i)
{
	ssize_t	index;

	index = find_key(reigns, buf + *i, 6 - *i);
	if (index == -1)
		return (NULL);
	return (get_key(reigns, buf + *i, 6 - *i));
}

int		perform_action(t_reigns* reigns, t_vec* input, char *buf)
{
	size_t					i;
	int						state;
	t_key					*key;

	state = RD_IDLE;
	i = 0;
	while (i < 6)
	{
		key = get_action(reigns, buf, &i);
		if (key && key->function)
		{
			state = key->function(reigns, input, buf + i, &key->hook);
			if (state != RD_IDLE)
				break ;
			i += key->size;
		}
		else
			i++;
	}
	return (state);
}
