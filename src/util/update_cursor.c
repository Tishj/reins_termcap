/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 13:36:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 17:13:34 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"

// static void	update_column(t_reigns* reigns, long long *col, long long *row)
// {


// }

void	update_cursor(t_reigns* reigns, int col_adjust, int row_adjust)
{
	long long col;
	long long row;
	col = (long long)reigns->input.nav.cursor.x + col_adjust;
	row = (long long)reigns->input.nav.cursor.y + row_adjust;
	//adjust column
	if (col >= (long long)reigns->nav.dimension.x)
	{
		col = 0;
		row++;
	}
	else if (col < 0)
	{
		if (row)
			col = reigns->nav.dimension.x - 1;
		else
			col = 0;
		row--;
	}
	//adjust row;
	if (row > (long long)reigns->input.nav.dimension.y)
		reigns->input.nav.dimension.y++;
	else if (row < 0)
		row = 0;
	reigns->input.nav.cursor.x = col;
	reigns->input.nav.cursor.y = row;
	reigns->nav.cursor.x = reigns->input.nav.cursor.x;
	if (!reigns->input.nav.cursor.y)
		reigns->nav.cursor.x += (reigns->input.start.x - 1);
}
