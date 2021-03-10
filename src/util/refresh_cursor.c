/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_cursor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:57:48 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 12:00:08 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>

void	refresh_cursor(t_reigns* reigns)
{
	while (reigns->term_cursor.row < 0)
	{
		termcmd(MOVE_COLROW, 0, 0, 1);
		termcmd(SCROLL_UP, 0, 0, 1);
		reigns->term_cursor.row++;
	}
	if (reigns->term_cursor.row >= (long long)reigns->term_rows)
	{
		reigns->term_cursor.row -= 1;
		reigns->prompt_row -= 1;
		termcmd(MOVE_COLROW, 0, reigns->term_rows, 1);
		termcmd(SCROLL_LINE, 0, 0, 1);
	}
	termcmd(MOVE_COLROW, reigns->term_cursor.col, reigns->term_cursor.row, 1);
}
