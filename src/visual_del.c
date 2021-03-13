/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_del.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:51:02 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 18:57:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

size_t	visual_del_row(t_input *input, size_t n, bool first)
{
	if ((long long)n > input->shell_cursor.col)
		n = input->shell_cursor.col;
	update_cursor(input, -(n - !first), 0);
	termcmd(MOVE_COLROW, input->term_cursor.col, input->term_cursor.row, 1);
	termcmd(DELETE_CHARS, n, n, n);
	return (n);
}

void	clear_later_rows(t_input *input)
{
	size_t	col;
	size_t	row;
	size_t	i;
	size_t	col_offset;

	col = input->shell_cursor.col;
	row = input->shell_cursor.row;
	i = 0;
	while (input->term_cursor.row + i < input->prompt_row + input->input_rows)
	{
		col_offset = (input->prompt_row == (input->term_cursor.row + i)) * input->prompt_size;
		termcmd(MOVE_COLROW, col_offset + (!i) * col, input->term_cursor.row + i, 1);
		termcmd("ce", 0, 0, 1);
		i++;
	}
	reins_cursor_move(input, col, row, true);
}

//count amount of rows deleted, those need to be cleared afterwards
void	visual_del(t_input *input, size_t n)
{
	size_t	i;

//	clear_later_rows(input);
	i = 0;
	while (i < n)
	{
		i += visual_del_row(input, (n - i), !i);
		if (i < n)
			update_cursor(input, -1, 0);
	}
}
