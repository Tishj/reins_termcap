/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_cursor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:57:48 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/05 18:00:28 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"

void	refresh_cursor(t_navigation* nav)
{
	if (nav->cursor.y < 0)
	{
		while (nav->cursor.y < 0)
		{
			termcmd(MOVE_COLROW, 0, 0, 1);
			termcmd(SCROLL_UP, 0, 0, 1);
			nav->cursor.y++;
		}
	}
	if (nav->cursor.y >= nav->dimension.y)
	{
		nav->cursor.y -= 1;
		termcmd(MOVE_COLROW, 0, nav->dimension.y, 1);
		termcmd(SCROLL_LINE, 0, 0, 1);
	}
	termcmd(MOVE_COLROW, nav->cursor.x, nav->cursor.y, 1);
}
