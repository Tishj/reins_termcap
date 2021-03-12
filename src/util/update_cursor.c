/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/12 17:19:34 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdbool.h>

static size_t	get_total_amount_of_columns(t_input *input, int col_adjust
	, int row_adjust, int offset)
{
	size_t	columns;

	columns = ((input->shell_cursor.row + row_adjust) * input->max_col)
		+ offset + input->shell_cursor.col + col_adjust;
	return (columns);
}

//needs to check if the index doesn't overflow to the next row, not just the cursor itself

//adding 9 characters to a line that would make the rest of the line overflow to the next row,
//but not the cursor itself is an example of the current issue

static size_t	rows_of_input(t_input *input)
{
	size_t	rows;

	rows = (input->line.size + input->prompt_size) / input->max_col;
	return (rows);
}

void	update_cursor(t_input *input, int col_adjust, int row_adjust)
{
	size_t	total;
	size_t	column_offset;

	column_offset = !input->shell_cursor.row * input->prompt_size;
	if (!input->shell_cursor.col && !input->shell_cursor.row
		&& col_adjust <= 0 && row_adjust <= 0)
		return ;
	if (row_adjust > 0 && row_adjust
		+ input->shell_cursor.row > (long long)input->input_rows)
		return ;
	total = get_total_amount_of_columns(input, col_adjust,
		row_adjust, column_offset);
	input->shell_cursor.row = total / input->max_col;
	input->term_cursor.row = input->prompt_row + input->shell_cursor.row;
	input->term_cursor.col = total % input->max_col;
	if (!input->shell_cursor.row)
		total -= input->prompt_size;
	input->shell_cursor.col = total % input->max_col;
	if (rows_of_input(input) >= input->input_rows)
		input->input_rows = rows_of_input(input) + 1;
}
