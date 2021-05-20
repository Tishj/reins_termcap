/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_find_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 18:08:14 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/20 18:14:45 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

void	*trie_find_str(t_trie *root, char *keycode)
{
	size_t	i;
	unsigned char *key;

	i = 0;
	key = (unsigned char*)keycode;
	while (root && key[i])
	{
		if (!root->children[(int)key[i]])
			break ;
		root = root->children[(int)key[i]];
		i++;
	}
	if (root && root->end && !key[i])
		return (root->val);
	return (NULL);
}
