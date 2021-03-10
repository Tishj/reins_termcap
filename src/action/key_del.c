/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_del.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:54:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 14:35:40 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

int	delete_from_affected_rows(t_reins *reins, t_vec *input)
{
	size_t	row;
	size_t	index;
	char	*buf;

	row = reins->shell_cursor.row;
	while (row + 1 < reins->input_rows)
	{
		termcmd(MOVE_COLROW, 0, reins->prompt_row + row + 1, 1);
		termcmd(DELETE_START, 0, 0, 1);
		termcmd(DELETE_CHAR, 0, 0, 1);
		termcmd(DELETE_END, 0, 0, 1);
		termcmd(MOVE_COLROW, reins->max_col, reins->prompt_row + row, 1);
		index = ((row + 1) * reins->max_col) - reins->prompt_size - 1;
		if (index >= input->size)
			break ;
		termcmd(INSERT_START, 0, 0, 1);
		buf = vec_getref(input, index);
		if (buf == NULL)
			return (0);
		write(1, buf, 1);
		termcmd(INSERT_END, 0, 0, 1);
		row++;
	}
	return (1);
}

int	key_del(t_reins *reins, t_vec *input, char *buf, t_hook *hook)
{
	size_t	index;

	if (hook && hook->function)
		hook->function(hook->param);
	(void)buf;
	if (!reins->shell_cursor.col)
		return (RD_IDLE);
	update_cursor(reins, -1, 0);
	index = (reins->shell_cursor.row * reins->max_col) + \
		reins->shell_cursor.col;
	if (reins->shell_cursor.row)
		index -= reins->prompt_size;
	if (!vec_del(input, index))
	{
		printf("vec_del failed!\n");
		return (RD_ERROR);
	}
	termcmd(MOVE_COLROW, reins->term_cursor.col,
		reins->term_cursor.row, 1);
	termcmd(DELETE_START, 0, 0, 1);
	termcmd(DELETE_CHAR, 0, 0, 1);
	termcmd(DELETE_END, 0, 0, 1);
	delete_from_affected_rows(reins, input);
	return (RD_IDLE);
}
