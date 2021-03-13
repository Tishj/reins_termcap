/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_del.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:41:34 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 19:30:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

static void	clear_later_lines(t_input *input)
{
	size_t	i;
	size_t	col;
	size_t	row;

	col = input->shell_cursor.col;
	row = input->shell_cursor.row;
	i = row;
	while (i < input->input_rows)
	{
		reins_cursor_move(input, 0 + ((i == row) * col), i, false);
		termcmd("ce", 0, 0, 1);
		i++;
	}
	reins_cursor_move(input, col, row, true);
}

int	reins_input_del(t_input *input, size_t n)
{
	size_t	index;
	char	*str;
	size_t	col;
	size_t	row;

	clear_later_lines(input);
	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (n > index)
		n = index;
	if (!vec_del(&input->line, index - n, n))
		return (RD_ERROR);
	str = vec_getref(&input->line, index - n);
	visual_del(input, n);
	col = input->shell_cursor.col;
	row = input->shell_cursor.row;
	if (index - n < input->line.size)
		visual_add(input, str, input->line.size - (index - n));
	reins_cursor_move(input, col, row, true);
	return (RD_IDLE);
}
