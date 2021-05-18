/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_insert.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:23:40 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/18 18:13:58 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

void	*trie_insert(t_trie **root, char *key, void *val)
{
	size_t	i;
	t_trie	*iter;

	if (!*root)
		*root = trie_new();
	i = 0;
	iter = *root;
	while (iter && key[i])
	{
		if (!iter->children[(int)key[i]])
			iter->children[(int)key[i]] = trie_new();
		iter = iter->children[(int)key[i]];
		i++;
	}
	if (iter && !key[i])
	{
		iter->val = val;
		iter->end = true;
		return (iter);
	}
	return (NULL);
}
