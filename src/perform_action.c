/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perform_action.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:25:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/23 00:42:43 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

t_key	*get_action(t_reins *reins, char *buf, size_t *i)
{
	t_node	**node;

	node = bstree_find(&reins->keys, buf, MAX_KEY_SIZE - *i, NULL);
	if (!*node)
		return (NULL);
	return ((*node)->val);
}

int	perform_action(t_reins *reins, t_input *input, char *buf)
{
	size_t					i;
	int						state;
	t_key					*key;

	state = RD_IDLE;
	i = 0;
	while (i < MAX_KEY_SIZE && buf[i])
	{
		key = get_action(reins, buf, &i);
		if (key && key->function)
		{
			state = key->function(input, buf + i, &key->hook);
			if (state != RD_IDLE)
				break ;
			i += key->size;
		}
		else
			i++;
	}
	return (state);
}
