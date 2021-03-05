/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_up.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:12:57 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

int	key_up(t_reigns* reigns, t_vec* input, char *buf)
{
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_IDLE);
}
