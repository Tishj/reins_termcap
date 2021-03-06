/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_regular.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:32:06 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 19:50:20 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

int		add_overflow_to_start_of_row(t_reigns* reigns, t_vec* input)
{
	size_t	index;
	size_t	row;
	char	*buf;

	row = reigns->input.nav.cursor.y;
	//for every row of the input
	while (row + 1 < reigns->input.nav.dimension.y)
	{
		//move to start of line
		termcmd(MOVE_COLROW, 0, reigns->input.start.y + row + 1, 1);
		index = ((row + 1) * reigns->nav.dimension.x) - reigns->input.start.x;
		if (index > input->index)
			break ;
		//insert character
		termcmd(INSERT_START, 0, 0, 1);
		if ((buf = vec_getref(input, index)) == NULL)
			return (0);
		write(1, buf, 1);
		termcmd(INSERT_END, 0, 0, 1);
		row++;
	}
	return (1);
}

// static void			set_pos_of_cursor(t_reigns *reigns)
// {
// 	if (reigns->input.nav.cursor.x + 1 > reigns->nav.dimension.x)
// 	{
// 		reigns->input.nav.cursor.x = 0;
// 		reigns->nav.cursor.x = 0;
// 		reigns->input.nav.cursor.y++;
// 		if (reigns->input.nav.cursor.y > reigns->input.nav.dimension.y)
// 			reigns->input.nav.dimension.y++;
// 		reigns->nav.cursor.y++;
// 	}
// 	else
// 		reigns->input.nav.cursor.x++;
// }

int	key_regular(t_reigns* reigns, t_vec* input, char *buf)
{
	size_t index;

	index = (reigns->input.nav.cursor.y * reigns->nav.dimension.x) +
		reigns->input.nav.cursor.x;
	if (!vec_insert(input, buf, index))
		return (RD_ERROR);
	termcmd(INSERT_START, 0, 0, 1);
	write(1, buf, 1);
	termcmd(INSERT_END, 0, 0, 1);
	if (!add_overflow_to_start_of_row(reigns, input))
		return (RD_ERROR);
	update_cursor(reigns, 1, 0);
//	termcmd(MOVE_COLROW, reigns->nav.cursor.x, reigns->nav.cursor.y, 1);
	return (RD_IDLE);
}
