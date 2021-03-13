/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_del.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:51:02 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 17:13:25 by tbruinem      ########   odam.nl         */
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

void	visual_del(t_input *input, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		i += visual_del_row(input, (n - i), !i);
		if (i < n)
			update_cursor(input, -1, 0);
	}
}
