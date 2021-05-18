/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_find.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:28:00 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/18 18:12:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

void	*trie_find(t_trie *root, char *c, int *ret)
{
	while (root && !root->end)
	{
		*ret = read(STDIN_FILENO, c, 1);
		if (!*ret)
			break ;
		root = root->children[(int)*c];
	}
	if (root)
		return (root->val);
	return (NULL);
}
