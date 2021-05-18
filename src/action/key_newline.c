/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_newline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:38:29 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/13 13:36:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>
#include <reins.h>

int	key_newline(t_input *input, char *buf, t_hook *hook)
{
	(void)buf;
	if (hook && hook->function)
		hook->function(hook->param);
	reins_cursor_move(input, input->max_col, input->input_rows, true);
	return (RD_SEND);
}
