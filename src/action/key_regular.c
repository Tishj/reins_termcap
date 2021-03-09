/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_regular.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:32:06 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:48:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int		add_overflow_to_start_of_row(t_reigns* reigns, t_vec* input)
{
	size_t	index;
	size_t	row;
	char	*buf;

	row = reigns->shell_cursor.row;
	//for every row of the input
	while (row + 1 < reigns->input_rows)
	{
		//move to start of line
		termcmd(MOVE_COLROW, 0, reigns->prompt_row + row + 1, 1);
		index = ((row + 1) * reigns->term_columns) - reigns->prompt_size;
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
// 	if (reigns->shell_cursor.col + 1 > reigns->term_columns)
// 	{
// 		reigns->shell_cursor.col = 0;
// 		reigns->term_cursor.col = 0;
// 		reigns->shell_cursor.row++;
// 		if (reigns->shell_cursor.row > reigns->input_rows)
// 			reigns->input_rows++;
// 		reigns->term_cursor.row++;
// 	}
// 	else
// 		reigns->shell_cursor.col++;
// }

int	key_regular(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	size_t index;

	if (hook && hook->function)
		hook->function(hook->param);
	index = (reigns->shell_cursor.row * reigns->term_columns) +
		reigns->shell_cursor.col;
	if (!vec_insert(input, buf, index))
		return (RD_ERROR);
	termcmd(INSERT_START, 0, 0, 1);
	write(1, buf, 1);
	termcmd(INSERT_END, 0, 0, 1);
	if (!add_overflow_to_start_of_row(reigns, input))
		return (RD_ERROR);
	update_cursor(reigns, 1, 0);
//	termcmd(MOVE_COLROW, reigns->term_cursor.col, reigns->term_cursor.row, 1);
	return (RD_IDLE);
}
