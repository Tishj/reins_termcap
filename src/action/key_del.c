/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:54:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 12:31:27 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

// static int			delete_from_affected_rows(t_reigns* reigns, t_vec* input)
// {
// 	size_t	row;
// 	size_t	index;
// 	char	*buf;

// 	row = reigns->input.nav.cursor.y;
// 	while (row < reigns->input.nav.dimension.y)
// 	{
// 		termcmd(MOVE_COLROW, 0, reigns->input.start.y + row + 1, 1);
// 		termcmd(DELETE_START, 0, 0, 1);
// 		termcmd(DELETE_CHAR, 0, 0, 1);
// 		termcmd(DELETE_END, 0, 0, 1);
// 		termcmd(MOVE_COLROW, reigns->input.nav.dimension.x, 
// 			reigns->input.start.y + row, 1);
// 		index = ((row + 1) * reigns->input.nav.dimension.x) -
// 			reigns->input.start.x - 1;
// 		if (index > input->index)
// 			break ;
// 		termcmd(INSERT_START, 0, 0, 1);
// 		if ((buf = vec_getref(input, index)) == NULL)
// 			return (0);
// 		write(1, buf, 1);
// 		termcmd(INSERT_END, 0, 0, 1);
// 		row++;
// 	}
// 	return (1);
// }

static void			set_pos_of_cursor(t_reigns* reigns)
{
	if (!reigns->input.nav.cursor.y && !reigns->input.nav.cursor.x)
		return ;
	if (reigns->input.nav.cursor.y && \
		reigns->input.nav.cursor.x == 0)
	{
		reigns->input.nav.cursor.y--;
		reigns->nav.cursor.y--;
		reigns->nav.cursor.x = reigns->nav.dimension.x - 1;
		reigns->input.nav.cursor.x = reigns->input.nav.dimension.x - 1;
	}
	else
	{
		reigns->nav.cursor.x--;
		reigns->input.nav.cursor.x--;
	}
}

int	key_del(t_reigns* reigns, t_vec* input, char *buf)
{
	size_t	index;
	size_t	column;

	(void)buf;
	set_pos_of_cursor(reigns);
	index = (reigns->input.nav.cursor.y * reigns->nav.dimension.x) + \
		reigns->input.nav.cursor.x;
	if (!vec_del(input, index))
		return (RD_ERROR);
	column = reigns->input.nav.cursor.x;
	if (!reigns->input.nav.cursor.y)
		column += reigns->input.start.x;
	termcmd(MOVE_COLROW, column - 1,
		reigns->input.start.y + reigns->input.nav.cursor.y, 1);
	termcmd(DELETE_START, 0, 0, 1);
	termcmd(DELETE_CHAR, 0, 0, 1);
	termcmd(DELETE_END, 0, 0, 1);
//	delete_from_affected_rows(reigns, input);
	return (RD_IDLE);
}
