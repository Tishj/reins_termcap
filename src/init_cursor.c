/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 21:13:22 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 21:45:39 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <reigns_int.h>
#include <stdio.h>
#include <termcap.h>

int	init_cursor(t_reigns* reigns)
{
	char		buf[10];
	int			ret;

	write(STDOUT_FILENO, KEY_ESC "[" "6n", 4);
	ret = read(STDIN_FILENO, buf, 10);
	if (ret == -1)
		return (!printf("read for cursor position failed!\n"));
//	print_keycode_formatted(buf, 10);
	reigns->term_cursor.row = util_atoi(buf + 2) - 1;
	reigns->term_cursor.col = util_atoi(buf + 4 + 
		(reigns->term_cursor.row >= 10) +
		(reigns->term_cursor.row > 100)) - 1;

	reigns->prompt_row = reigns->term_cursor.row;
	reigns->prompt_size = reigns->term_cursor.col;
	
	reigns->input_rows = 0;
	reigns->shell_cursor.col = 0;
	reigns->shell_cursor.row = 0;
	reigns->term_columns = tgetnum("co");
	reigns->term_rows = tgetnum("li");
	return (1);
}
