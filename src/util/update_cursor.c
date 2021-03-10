/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 11:48:53 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <stdbool.h>

void	update_cursor(t_reigns* reigns, int col_adjust, int row_adjust)
{
	size_t	total;
	size_t	column_offset;

	column_offset = !reigns->shell_cursor.row * reigns->prompt_size;
	//cant move back on row 0 col 0
	if (!reigns->shell_cursor.col && !reigns->shell_cursor.row
		&& col_adjust <= 0 && row_adjust <= 0)
		return ;
	if (row_adjust > 0 && row_adjust
		+ reigns->shell_cursor.row > (long long)reigns->input_rows)
		return ;

	//total columns, including prompt_size
	total = ((reigns->shell_cursor.row + row_adjust) * reigns->term_columns)
		+ column_offset + reigns->shell_cursor.col + col_adjust;
	reigns->shell_cursor.row = total / reigns->term_columns;
	reigns->term_cursor.row = reigns->prompt_row + reigns->shell_cursor.row;
	
	reigns->term_cursor.col = total % reigns->term_columns;
	if (!reigns->shell_cursor.row)
		total -= reigns->prompt_size;
	reigns->shell_cursor.col = total % reigns->term_columns;

	//increase size of input height
	if (reigns->shell_cursor.row >= (long long)reigns->input_rows)
		reigns->input_rows = reigns->shell_cursor.row + 1;
}
