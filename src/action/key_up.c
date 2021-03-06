/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_up.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 12:34:45 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

int	key_up(t_reigns* reigns, t_vec* input, char *buf)
{
	// int state = key_newline(reigns, input, buf);
	// write(1, "UP\n", 3);
	// return (state);
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_IDLE);
}
