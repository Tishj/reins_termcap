/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:19:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/18 20:07:53 by tbruinem      ########   odam.nl         */
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
	util_memset(new->children, 0, 255 * sizeof(t_trie*));
	new->end = false;
	new->val = NULL;
	return (new);
}
