/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:46:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:13:05 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <reigns_int.h>

void	reigns_destroy(t_reigns* reigns)
{
	free(reigns);
}
