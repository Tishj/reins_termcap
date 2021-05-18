/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perform_action.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:25:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/05/18 20:15:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

//might break if an unrecognized key preceeds a known one
int	perform_action(t_reins *reins, t_input *input)
{
	int						state;
	t_key					*key;
	int						ret;\
	char					c;

	state = RD_IDLE;
	ret = 1;
	while (ret)
	{
		key = trie_find(reins->keys, &c, &ret);
		if (key && key->function)
			state = key->function(input, &c, &key->hook);
		if (state != RD_IDLE)
			break ;
	}
	return (state);
}
