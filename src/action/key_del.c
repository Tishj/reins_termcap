/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:54:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 00:29:28 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int			delete_from_affected_rows(t_reigns* reigns, t_vec* input)
{
	size_t	row;
	size_t	index;
	char	*buf;

	row = reigns->input.nav.cursor.y;
	while (row < reigns->input.nav.dimension.y)
	{
		termcmd(MOVE_COLROW, 0, reigns->input.start.y + row + 1, 1);
		termcmd(DELETE_START, 0, 0, 1);
		termcmd(DELETE_CHAR, 0, 0, 1);
		termcmd(DELETE_END, 0, 0, 1);
		termcmd(MOVE_COLROW, reigns->input.nav.dimension.x, 
			reigns->input.start.y + row, 1);
		index = ((row + 1) * reigns->input.nav.dimension.x) -
			reigns->input.start.x - 1;
		if (index > input->index)
			break ;
		termcmd(INSERT_START, 0, 0, 1);
		if ((buf = vec_getref(input, index)) == NULL)
			return (0);
		write(1, buf, 1);
		termcmd(INSERT_END, 0, 0, 1);
		row++;
	}
	return (1);
}

int	key_del(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	size_t	index;

	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	update_cursor(reigns, -1, 0);
	index = (reigns->input.nav.cursor.y * reigns->nav.dimension.x) + \
		reigns->input.nav.cursor.x;
	if (!vec_del(input, index))
		return (RD_ERROR);
	termcmd(MOVE_COLROW, reigns->nav.cursor.x,
		reigns->nav.cursor.y, 1);
	termcmd(DELETE_START, 0, 0, 1);
	termcmd(DELETE_CHAR, 0, 0, 1);
	termcmd(DELETE_END, 0, 0, 1);
//	delete_from_affected_rows(reigns, input);
	return (RD_IDLE);
}
