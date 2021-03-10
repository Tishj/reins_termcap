/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 13:17:26 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdbool.h>

void	update_cursor(t_reins* reins, int col_adjust, int row_adjust)
{
	size_t	total;
	size_t	column_offset;

	column_offset = !reins->shell_cursor.row * reins->prompt_size;
	//cant move back on row 0 col 0
	if (!reins->shell_cursor.col && !reins->shell_cursor.row
		&& col_adjust <= 0 && row_adjust <= 0)
		return ;
	if (row_adjust > 0 && row_adjust
		+ reins->shell_cursor.row > (long long)reins->input_rows)
		return ;

	//total columns, including prompt_size
	total = ((reins->shell_cursor.row + row_adjust) * reins->max_col)
		+ column_offset + reins->shell_cursor.col + col_adjust;
	reins->shell_cursor.row = total / reins->max_col;
	reins->term_cursor.row = reins->prompt_row + reins->shell_cursor.row;
	
	reins->term_cursor.col = total % reins->max_col;
	if (!reins->shell_cursor.row)
		total -= reins->prompt_size;
	reins->shell_cursor.col = total % reins->max_col;

	//increase size of input height
	if (reins->shell_cursor.row >= (long long)reins->input_rows)
		reins->input_rows = reins->shell_cursor.row + 1;
}
