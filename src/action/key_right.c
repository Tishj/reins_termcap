/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_right.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/13 17:48:57 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

static size_t	index_of_cursor(t_input *input)
{
	size_t	index;

	index = (input->shell_cursor.row * input->max_col)
		- (!!input->shell_cursor.row * input->prompt_size)
		+ input->shell_cursor.col;
	return (index);
}

int	key_right(t_input *input, char *buf, t_hook *hook)
{
//	size_t	max_row;
//	size_t	max_col;

	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if (index_of_cursor(input) >= input->line.size)
		return (RD_IDLE);
	update_cursor(input, 1, 0);
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (RD_IDLE);
}
