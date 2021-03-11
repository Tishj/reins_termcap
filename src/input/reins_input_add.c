/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 11:59:11 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/11 20:48:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

//todo:
//might not work for len bigger than max_col
int	add_overflow_to_start_of_row(t_input *input, size_t len)
{
	size_t	index;
	size_t	row;
	char	*buf;

	row = input->shell_cursor.row;
	while (row + 1 < input->input_rows)
	{
		termcmd(MOVE_COLROW, 0, input->prompt_row + row + 1, 1);
		index = ((row + 1) * input->max_col) - input->prompt_size - (len - 1);
		if (index >= input->line.size)
			break ;
		termcmd(INSERT_START, 0, 0, 1);
		buf = vec_getref(&input->line, index);
		if (buf == NULL)
			return (0);
		write(1, buf, len);
		termcmd(INSERT_END, 0, 0, 1);
		row++;
	}
	return (1);
}

//probably check if len is over input->max_row and act accordingly
int	reins_input_add(t_input *input, char *str, size_t len)
{
	size_t	index;

	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (!vec_insert(&input->line, str, index, len))
	{
		printf("vec_insert failed\n");
		return (RD_ERROR);
	}
	termcmd(INSERT_START, 0, 0, 1);
	write(1, str, len);
	termcmd(INSERT_END, 0, 0, 1);
	update_cursor(input, len, 0);
	if (!add_overflow_to_start_of_row(input, len))
	{
		printf("add_overflow failed\n");
		return (RD_ERROR);
	}
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (1);
}
