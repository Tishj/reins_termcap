/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_destroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:59:10 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/20 18:22:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

void	trie_destroy(t_trie *trie)
{
	size_t	i;

	i = 0;
	if (trie && trie->end)
		free(trie->val);
	while (trie && i < TRIE_CHILDREN_AMOUNT)
	{
		if (trie->children[i])
			trie_destroy(trie->children[i]);
		i++;
	}
	free(trie);
}
