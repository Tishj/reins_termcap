/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_up.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 00:28:57 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>
#include <stdio.h>

int	key_up(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	// int state = key_newline(reigns, input, buf);
	// write(1, "UP\n", 3);
	// return (state);
	if (hook && hook->function)
		hook->function(hook->param);
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_IDLE);
}
