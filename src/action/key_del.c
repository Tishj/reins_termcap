/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:54:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:48:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int			delete_from_affected_rows(t_reigns* reigns, t_vec* input)
{
	size_t	row;
	size_t	index;
	char	*buf;

	row = reigns->shell_cursor.row;
	while (row < reigns->input_rows)
	{
		termcmd(MOVE_COLROW, 0, reigns->prompt_row + row + 1, 1);
		termcmd(DELETE_START, 0, 0, 1);
		termcmd(DELETE_CHAR, 0, 0, 1);
		termcmd(DELETE_END, 0, 0, 1);
		termcmd(MOVE_COLROW, reigns->term_columns, 
			reigns->prompt_row + row, 1);
		index = ((row + 1) * reigns->term_columns) -
			reigns->prompt_size - 1;
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
	index = (reigns->shell_cursor.row * reigns->term_columns) + \
		reigns->shell_cursor.col;
	if (!vec_del(input, index))
		return (RD_ERROR);
	termcmd(MOVE_COLROW, reigns->term_cursor.col,
		reigns->term_cursor.row, 1);
	termcmd(DELETE_START, 0, 0, 1);
	termcmd(DELETE_CHAR, 0, 0, 1);
	termcmd(DELETE_END, 0, 0, 1);
//	delete_from_affected_rows(reigns, input);
	return (RD_IDLE);
}
