/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 14:44:45 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 15:26:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>
#include <unistd.h>

static size_t	maximum_columns_left_on_row(t_input *input)
{
	size_t	max_cols;

	max_cols = input->max_col
		- (!input->shell_cursor.row * input->prompt_size)
		- input->shell_cursor.col;
	return (max_cols);
}

static size_t	visual_add_row(t_input *input, char *str, size_t amount)
{
	size_t	max_cols;

	max_cols = maximum_columns_left_on_row(input);
	if (amount > max_cols)
		amount = max_cols;
	termcmd("ce", 0, 0, 1);
	termcmd(INSERT_START, 0, 0, 1);
	write(1, str, amount);
	termcmd(INSERT_END, 0, 0, 1);
	update_cursor(input, amount, 0);
	refresh_cursor(input);
	return (amount);
}

void	visual_add(t_input *input, char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		i += visual_add_row(input, buffer + i, (size - i));
}
