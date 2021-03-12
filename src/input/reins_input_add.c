/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 11:59:11 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/12 17:28:02 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

static size_t	maximum_columns_left_on_row(t_input *input)
{
	size_t max_cols;

	max_cols = input->max_col
		- (!input->shell_cursor.row * input->prompt_size)
		- input->shell_cursor.col;
	return (max_cols);
}

static size_t	add_single_row(t_input *input, char *str, size_t amount)
{
	size_t	max_cols;
//	size_t	row;

	max_cols = maximum_columns_left_on_row(input);
	if (amount > max_cols)
		amount = max_cols;
	termcmd(INSERT_START, 0, 0, 1);
	write(1, str, amount);
	termcmd(INSERT_END, 0, 0, 1);
	update_cursor(input, amount, 0);
	refresh_cursor(input);
	return (amount);
}

static int	wrap_around_characters(t_input *input, size_t row, size_t len, size_t offset)
{
	size_t	index;
	char	*buf;

	if (row + 1 >= input->input_rows)
		return (1);
	while (row + 1 < input->input_rows)
	{
		//move to start of next row
		termcmd(MOVE_COLROW, 0, input->prompt_row + row + 1, 1);
		//get index of last column, previous row
		index = ((row + 1) * input->max_col) - input->prompt_size + offset;
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

int	reins_input_add(t_input *input, char *str, size_t len)
{
	size_t	index;
	size_t	amount;
	size_t	row;

	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (!vec_insert(&input->line, str, index, len))
		return (error("vec_insert failed", RD_ERROR));
	index = 0;
	while (index < len)
	{
		termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
		row = input->shell_cursor.row;
		amount = add_single_row(input, str + index, (len - index));
		if (!wrap_around_characters(input, row, amount, len - amount))
			return (RD_ERROR);
		index += amount;
	}
	//refresh_cursor(input);
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (RD_IDLE);
}
