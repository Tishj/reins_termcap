/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_right.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:48:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int	key_right(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if ((reigns->shell_cursor.row * reigns->term_columns) + 
		reigns->shell_cursor.col >= input->index)
		return (RD_IDLE);
	update_cursor(reigns, 1, 0);
	termcmd(MOVE_COLROW, reigns->term_cursor.col, reigns->term_cursor.row, 1);
	return (RD_IDLE);
}
