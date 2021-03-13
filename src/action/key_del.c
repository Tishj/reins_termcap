/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:54:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/13 17:42:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

int	delete_from_affected_rows(t_input *input)
{
	size_t	row;
	size_t	index;
	char	*buf;

	row = input->shell_cursor.row;
	while (row + 1 < input->input_rows)
	{
		termcmd(MOVE_COLROW, 0, input->prompt_row + row + 1, 1);
		termcmd(DELETE_START, 0, 0, 1);
		termcmd(DELETE_CHAR, 0, 0, 1);
		termcmd(DELETE_END, 0, 0, 1);
		termcmd(MOVE_COLROW, input->max_col, input->prompt_row + row, 1);
		index = ((row + 1) * input->max_col) - input->prompt_size - 1;
		if (index >= input->line.size)
			break ;
		termcmd(INSERT_START, 0, 0, 1);
		buf = vec_getref(&input->line, index);
		if (buf == NULL)
			return (0);
		write(1, buf, 1);
		termcmd(INSERT_END, 0, 0, 1);
		row++;
	}
	return (1);
}

int	key_del(t_input *input, char *buf, t_hook *hook)
{
	size_t	index;

	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if (!input->shell_cursor.row && !input->shell_cursor.col)
		return (RD_IDLE);
	update_cursor(input, -1, 0);
	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (input->shell_cursor.row)
		index -= input->prompt_size;
	if (!vec_del(&input->line, index, 1))
	{
		printf("vec_del failed!\n");
		return (RD_ERROR);
	}
	termcmd(MOVE_COLROW, input->term_cursor.col,
		input->term_cursor.row, 1);
	termcmd(DELETE_START, 0, 0, 1);
	termcmd(DELETE_CHAR, 0, 0, 1);
	termcmd(DELETE_END, 0, 0, 1);
	delete_from_affected_rows(input);
	return (RD_IDLE);
}
