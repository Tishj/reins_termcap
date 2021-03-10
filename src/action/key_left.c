/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_left.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:46:47 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

int	key_left(t_reins *reins, t_vec *input, char *buf, t_hook *hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	(void)input;
	if (reins->shell_cursor.col <= 0 && !reins->shell_cursor.row)
		return (RD_IDLE);
	update_cursor(reins, -1, 0);
	termcmd(MOVE_COLROW, reins->term_cursor.col, reins->term_cursor.row, 1);
	return (RD_IDLE);
}
