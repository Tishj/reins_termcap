/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 11:59:11 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/12 14:14:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

size_t	maximum_columns_left_on_row(t_input *input)
{
	size_t max_cols;

	max_cols = input->max_col
		- (!input->shell_cursor.row * input->prompt_size)
		- input->shell_cursor.col;
	return (max_cols);
}

// static int	add_overflow_to_start_of_row(t_input *input, size_t len, size_t rows, size_t offset)
// {
// 	size_t	index;
// 	size_t	row;
// 	char	*buf;

// 	row = input->shell_cursor.row;
// 	while (row + rows < input->input_rows)
// 	{

// 		termcmd(MOVE_COLROW, 0, input->prompt_row + row + rows, 1);
// 		//get index of last column, previous row
// 		index = ((row + rows) * input->max_col) - input->prompt_size + len;
// 		if (index >= input->line.size)
// 			break ;
// 		termcmd(INSERT_START, 0, 0, 1);
// 		//get ch
// 		buf = vec_getref(&input->line, index + offset);
// 		if (buf == NULL)
// 			return (0);
// 		write(1, buf, len);
// 		termcmd(INSERT_END, 0, 0, 1);
// 		row++;
// 	}
// 	return (1);
// }

size_t	add_single_row(t_input *input, char *str, size_t amount)
{
	size_t max_cols;

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

//probably check if len is over input->max_row and act accordingly
int	reins_input_add(t_input *input, char *str, size_t len)
{
	size_t	index;
//	size_t	offset;

	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (!vec_insert(&input->line, str, index, len))
	{
		printf("vec_insert failed\n");
		return (RD_ERROR);
	}
//	offset = index;
	index = 0;
	while (index < len)
		index += add_single_row(input, str + index, (len - index));
	// if (!add_overflow_to_start_of_row(input, len, 1, offset))
	// {
	// 	printf("add_overflow failed\n");
	// 	return (RD_ERROR);
	// }
	//refresh_cursor(input);
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (RD_IDLE);
}
