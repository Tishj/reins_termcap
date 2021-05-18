/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 21:13:22 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/11 22:18:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <reins_int.h>
#include <stdio.h>
#include <termcap.h>
#include <reins.h>

int	init_cursor(t_input *input)
{
	char		buf[10];
	int			ret;

	write(STDOUT_FILENO, KEY_ESC "[" "6n", 4);
	ret = read(STDIN_FILENO, buf, 10);
	if (ret == -1)
		return (!printf("read for cursor position failed!\n"));
	input->term_cursor.row = util_atoi(buf + 2) - 1;
	input->term_cursor.col = util_atoi(buf + 4
			+ (input->term_cursor.row >= 9)
			+ (input->term_cursor.row >= 99)) - 1;
	input->prompt_row = input->term_cursor.row;
	input->prompt_size = input->term_cursor.col;
	input->input_rows = 1;
	input->shell_cursor.col = 0;
	input->shell_cursor.row = 0;
	input->max_col = tgetnum("co");
	input->max_row = tgetnum("li");
	return (1);
}
