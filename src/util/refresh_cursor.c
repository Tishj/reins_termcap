/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_cursor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:57:48 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:17:04 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

void	refresh_cursor(t_input *input)
{
	while (input->term_cursor.row < 0)
	{
		termcmd(MOVE_COLROW, 0, 0, 1);
		termcmd(SCROLL_UP, 0, 0, 1);
		input->term_cursor.row++;
	}
	if (input->term_cursor.row >= (long long)input->max_row)
	{
		input->term_cursor.row -= 1;
		input->prompt_row -= 1;
		termcmd(MOVE_COLROW, 0, input->max_row, 1);
		termcmd(SCROLL_LINE, 0, 0, 1);
	}
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
}
