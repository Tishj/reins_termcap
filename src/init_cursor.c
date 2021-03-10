/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 21:13:22 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 14:04:32 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <reins_int.h>
#include <stdio.h>
#include <termcap.h>

int	init_cursor(t_reins* reins)
{
	char		buf[10];
	int			ret;

	write(STDOUT_FILENO, KEY_ESC "[" "6n", 4);
	ret = read(STDIN_FILENO, buf, 10);
	if (ret == -1)
		return (!printf("read for cursor position failed!\n"));
//	print_keycode_formatted(buf, 10);
	reins->term_cursor.row = util_atoi(buf + 2) - 1;
	reins->term_cursor.col = util_atoi(buf + 4 + 
		(reins->term_cursor.row >= 9) +
		(reins->term_cursor.row > 99)) - 1;

//	printf("COL: %lld | ROW: %lld\n", reins->term_cursor.col, reins->term_cursor.row);
	reins->prompt_row = reins->term_cursor.row;
	reins->prompt_size = reins->term_cursor.col;
	
	reins->input_rows = 1;
	reins->shell_cursor.col = 0;
	reins->shell_cursor.row = 0;
	reins->max_col = tgetnum("co");
	reins->max_row = tgetnum("li");
	// termcmd(MOVE_COLROW, reins->term_cursor.col,
	// 	reins->term_cursor.row, 1);
	return (1);
}
