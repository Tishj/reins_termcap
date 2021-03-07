/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_down.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 00:29:22 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int	key_down(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_IDLE);
}
