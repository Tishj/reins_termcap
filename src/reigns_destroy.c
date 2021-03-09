/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:46:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 12:03:08 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <reigns_int.h>

void	reigns_destroy(t_reigns* reigns)
{
	vec_destroy(&reigns->keys, NULL);
	free(reigns);
}
