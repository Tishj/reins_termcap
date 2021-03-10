/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_regular.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:32:06 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 14:07:08 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <stdio.h>

int		add_overflow_to_start_of_row(t_reins* reins, t_vec* input)
{
	size_t	index;
	size_t	row;
	char	*buf;

	row = reins->shell_cursor.row;
	//for every row of the input
	while (row + 1 < reins->input_rows)
	{
		//move to start of line
		termcmd(MOVE_COLROW, 0, reins->prompt_row + row + 1, 1);
		index = ((row + 1) * reins->max_col) - reins->prompt_size;
		if (index >= input->index)
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

int	key_regular(t_reins* reins, t_vec* input, char *buf, t_hook* hook)
{
	size_t index;

	if (hook && hook->function)
		hook->function(hook->param);
	index = (reins->shell_cursor.row * reins->max_col) +
		reins->shell_cursor.col;
	if (!vec_insert(input, buf, index))
	{
		printf("vec_insert failed\n");
		return (RD_ERROR);
	}
	termcmd(INSERT_START, 0, 0, 1);
	write(1, buf, 1);
	termcmd(INSERT_END, 0, 0, 1);
	update_cursor(reins, 1, 0);
	if (!add_overflow_to_start_of_row(reins, input))
	{
		printf("add_overflow failed\n");
		return (RD_ERROR);
	}
	termcmd(MOVE_COLROW, reins->term_cursor.col, reins->term_cursor.row, 1);
	return (RD_IDLE);
}
