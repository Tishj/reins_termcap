/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_clear.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 13:50:47 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 13:56:38 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

int	reins_input_clear(t_input *input)
{
	if (!vec_del(&input->line, 0, input->line.size))
		return (RD_ERROR);
	reins_cursor_move(input, 0, 0, true);
	input->input_rows = 1;
	return (RD_IDLE);
}
