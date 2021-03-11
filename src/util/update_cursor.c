/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:11:11 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdbool.h>

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
	total = ((input->shell_cursor.row + row_adjust) * input->max_col)
		+ column_offset + input->shell_cursor.col + col_adjust;
	input->shell_cursor.row = total / input->max_col;
	input->term_cursor.row = input->prompt_row + input->shell_cursor.row;
	input->term_cursor.col = total % input->max_col;
	if (!input->shell_cursor.row)
		total -= input->prompt_size;
	input->shell_cursor.col = total % input->max_col;
	if (input->shell_cursor.row >= (long long)input->input_rows)
		input->input_rows = input->shell_cursor.row + 1;
}
