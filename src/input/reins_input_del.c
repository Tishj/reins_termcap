/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_del.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:41:34 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 17:08:20 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

int	reins_input_del(t_input *input, size_t n)
{
	size_t	index;
//	size_t	col;
//	size_t	row;
	char	*str;

	index = (input->shell_cursor.row * input->max_col)
		- ((!!input->shell_cursor.row) * input->prompt_size)
		+ input->shell_cursor.col;
	if (n > index || !vec_del(&input->line, index - n, n))
		return (RD_ERROR);
	str = vec_getref(&input->line, index - n);
//	col = input->shell_cursor.col;
//	row = input->shell_cursor.row;
	visual_del(input, n);
//	reins_cursor_move(input, col, row, true);
	visual_add(input, str, input->line.size - (index - n));
	return (RD_IDLE);
}
