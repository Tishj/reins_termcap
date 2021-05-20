/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_insert.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:23:40 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/20 17:53:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

void	*trie_insert(t_trie **root, char *key, void *val)
{
	size_t			i;
	t_trie			*iter;
	unsigned char	*ukey;

	if (!*root)
		*root = trie_new();
	i = 0;
	iter = *root;
	ukey = (unsigned char*)key;
	while (iter && ukey[i])
	{
		if (ukey[i] > TRIE_CHILDREN_AMOUNT - 1)
			return (NULL);
		if (!iter->children[(int)ukey[i]])
			iter->children[(int)ukey[i]] = trie_new();
		iter = iter->children[(int)ukey[i]];
		i++;
	}
	if (iter && !ukey[i])
	{
		if (iter->end)
			free(iter->val);
		iter->val = val;
		iter->end = true;
		return (iter);
	}
	return (NULL);
}
