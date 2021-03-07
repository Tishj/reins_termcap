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

#include <reigns_int.h>

int	key_eof(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	(void)hook;
	(void)reigns;
	(void)buf;
	if (input->index)
		return (RD_IDLE);
	return (RD_EOF);
}
