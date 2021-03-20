/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_cursor_move.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 12:59:00 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/20 16:03:42 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

static size_t	row(t_input *input, size_t y, size_t total)
{
	size_t	max;

	max = total / input->max_col;
	if (y > max)
		return (max);
	return (y);
}

static size_t	column(t_input *input, size_t x, size_t y, size_t total)
{
	size_t	max;

	if (y + 1 == input->input_rows)
		max = total % input->max_col;
	if (!y)
		max -= input->prompt_size;
	if (x > max)
		return (max);
	return (x);
}

int	reins_cursor_move(t_input *input, size_t x, size_t y, bool cap)
{
	size_t	total_columns;

	total_columns = input->prompt_size + input->line.size;
	if (cap)
	{
		y = row(input, y, total_columns);
		x = column(input, x, y, total_columns);
	}
	input->term_cursor.col = x + ((!y) * input->prompt_size);
	input->term_cursor.row = y + input->prompt_row;
	input->shell_cursor.row = y;
	input->shell_cursor.col = x;
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (1);
}
