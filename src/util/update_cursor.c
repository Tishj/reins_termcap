/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:48:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

void	update_cursor(t_reigns* reigns, int col_adjust, int row_adjust)
{
	long long col;
	long long row;
	col = (long long)reigns->shell_cursor.col + col_adjust;
	row = (long long)reigns->shell_cursor.row + row_adjust;
	//adjust column
	if (col >= (long long)reigns->term_columns)
	{
		col = 0;
		row++;
	}
	else if (col < 0)
	{
		if (row)
			col = reigns->term_columns - 1;
		else
			col = 0;
		row--;
	}
	//adjust row;
	if (row > (long long)reigns->input_rows)
		reigns->input_rows++;
	else if (row < 0)
		row = 0;
	reigns->shell_cursor.col = col;
	reigns->shell_cursor.row = row;
	reigns->term_cursor.col = reigns->shell_cursor.col;
	if (!reigns->shell_cursor.row)
		reigns->term_cursor.col += (reigns->prompt_size - 1);
}
