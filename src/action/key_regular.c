/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_regular.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:32:06 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:23:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

int	add_overflow_to_start_of_row(t_input *input)
{
	size_t	index;
	size_t	row;
	char	*buf;

	row = input->shell_cursor.row;
	while (row + 1 < input->input_rows)
	{
		termcmd(MOVE_COLROW, 0, input->prompt_row + row + 1, 1);
		index = ((row + 1) * input->max_col) - input->prompt_size;
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

int	key_regular(t_input *input, char *buf, t_hook *hook)
{
	size_t	index;

	if (hook && hook->function)
		hook->function(hook->param);
	index = (input->shell_cursor.row * input->max_col)
		+ input->shell_cursor.col;
	if (!vec_insert(&input->line, buf, index, 1))
	{
		printf("vec_insert failed\n");
		return (RD_ERROR);
	}
	termcmd(INSERT_START, 0, 0, 1);
	write(1, buf, 1);
	termcmd(INSERT_END, 0, 0, 1);
	update_cursor(input, 1, 0);
	if (!add_overflow_to_start_of_row(input))
	{
		printf("add_overflow failed\n");
		return (RD_ERROR);
	}
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (RD_IDLE);
}
