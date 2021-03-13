/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_cursor_move.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 12:59:00 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 15:31:41 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

int	reins_cursor_move(t_input *input, size_t x, size_t y, bool cap)
{
	size_t	total_columns;
	size_t	max_row;
	size_t	max_col;

	total_columns = input->prompt_size + input->line.size;
	max_row = total_columns / input->max_col;
	max_col = total_columns % input->max_col;
	if (!cap && (x >= max_col || y >= max_row))
		return (0);
	if (x >= input->max_col)
		x = input->max_col;
	if (y >= max_row)
	{
		y = max_row;
		if (x > max_col)
			x = max_col;
	}
	input->term_cursor.row = input->prompt_row + y;
	input->term_cursor.col = x;
	if (!y)
		input->term_cursor.col += input->prompt_size;
	input->shell_cursor.col = x;
	input->shell_cursor.row = y;
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	return (1);
}
