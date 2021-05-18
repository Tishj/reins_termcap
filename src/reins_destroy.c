/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:46:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 12:03:08 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <reins_int.h>
#include <reins.h>

void	reins_destroy(t_reins *reins)
{
	reins_disable(reins);
	trie_destroy(reins->keys);
	free(reins);
}
