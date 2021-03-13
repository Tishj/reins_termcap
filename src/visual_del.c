/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_del.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:51:02 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 20:28:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

static size_t	max_columns(t_input *input)
{
	size_t	columns;
	size_t	row;
	
	row = input->shell_cursor.row - (!input->shell_cursor.col);
	columns = input->max_col - (!row * input->prompt_size);
	if (!input->shell_cursor.col)
		return (columns);
	return (input->shell_cursor.col);
}

size_t	visual_del_row(t_input *input, size_t n, bool first)
{
	size_t	columns;

	(void)first;
	columns = max_columns(input);
	if (n > columns)
		n = columns;
	update_cursor(input, -n, 0);
	refresh_cursor(input);
	termcmd(DELETE_CHARS, n, n, n);
	return (n);
}

void	visual_del(t_input *input, size_t n)
{
	size_t	i;
	size_t	deleted;

	i = 0;
	while (i < n)
	{
		deleted = visual_del_row(input, (n - i), !!i);
		if (!deleted)
			break ;
		i += deleted;
	}
	refresh_cursor(input);
}
