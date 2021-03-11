/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_right.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:11:34 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

int	key_right(t_input *input, char *buf, t_hook *hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if ((input->shell_cursor.row * input->max_col)
		+ input->shell_cursor.col >= input->line.size)
		return (RD_IDLE);
	update_cursor(input, 1, 0);
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (RD_IDLE);
}
