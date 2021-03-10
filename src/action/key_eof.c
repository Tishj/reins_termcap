/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_eof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:31:26 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:54:42 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

int	key_eof(t_reins* reins, t_vec* input, char *buf, t_hook* hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)reins;
	(void)buf;
	if (input->index)
		return (RD_IDLE);
	return (RD_EOF);
}
