/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_clear.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 13:50:47 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/20 16:04:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

int	reins_input_clear(t_input *input)
{
	reins_cursor_move(input, input->max_col, input->input_rows, true);
	return (reins_input_del(input, input->line.size));
}
