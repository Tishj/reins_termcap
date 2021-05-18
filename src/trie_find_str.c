/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_find_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 18:08:14 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/18 18:13:14 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

void	*trie_find_str(t_trie *root, char *keycode)
{
	size_t	i;

	i = 0;
	while (root && keycode[i])
	{
		if (!root->children[(int)keycode[i]])
			break ;
		root = root->children[(int)keycode[i]];
		i++;
	}
	if (root && root->end && !keycode[i])
		return (root->val);
	return (NULL);
}
