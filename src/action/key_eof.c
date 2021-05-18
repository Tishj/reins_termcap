/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_eof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:31:26 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:13:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

int	key_eof(t_input *input, char *buf, t_hook *hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if (input->line.size)
		return (RD_IDLE);
	return (RD_EOF);
}
