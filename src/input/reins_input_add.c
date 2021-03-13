/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 11:59:11 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 15:00:00 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>
#include <unistd.h>
#include <stdio.h>

int	reins_input_add(t_input *input, char *str, size_t len)
{
	size_t	index;
	size_t	col;
	size_t	row;

	//add to vector
	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (!vec_insert(&input->line, str, index, len))
		return (error("vec_insert failed", RD_ERROR));
	//add visually
	visual_add(input, str, len);
	col = input->shell_cursor.col;
	row = input->shell_cursor.row;
	str = vec_getref(&input->line, index + len);
	visual_add(input, str, input->line.size - (index + len));
	reins_cursor_move(input, col, row, true);
	refresh_cursor(input);
	return (RD_IDLE);
}
