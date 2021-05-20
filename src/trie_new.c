/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:19:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/20 18:07:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

t_trie	*trie_new(void)
{
	t_trie	*new;

	new = malloc(sizeof(t_trie));
	if (!new)
		return (NULL);
	util_memset(new->children, 0, TRIE_CHILDREN_AMOUNT * sizeof(t_trie*));
	new->end = false;
	new->val = NULL;
	return (new);
}
