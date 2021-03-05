/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:46:23 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/05 17:47:59 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <stdlib.h>

void	reigns_destroy(t_reigns* reigns)
{
	free(reigns);
}
