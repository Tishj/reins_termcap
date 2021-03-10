/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_cursor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:57:48 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 13:02:05 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

//really needs a better name
void	refresh_cursor(t_reins *reins)
{
	while (reins->term_cursor.row < 0)
	{
		termcmd(MOVE_COLROW, 0, 0, 1);
		termcmd(SCROLL_UP, 0, 0, 1);
		reins->term_cursor.row++;
	}
	if (reins->term_cursor.row >= (long long)reins->max_row)
	{
		reins->term_cursor.row -= 1;
		reins->prompt_row -= 1;
		termcmd(MOVE_COLROW, 0, reins->max_row, 1);
		termcmd(SCROLL_LINE, 0, 0, 1);
	}
	termcmd(MOVE_COLROW, reins->term_cursor.col, reins->term_cursor.row, 1);
}
