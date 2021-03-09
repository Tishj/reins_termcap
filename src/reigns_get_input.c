/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_get_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:04:02 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 16:48:43 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <vector.h>
#include <stdio.h>
#include <termcap.h>
#include <reigns_int.h>

static int	get_cursor_pos(t_reigns* reigns)
{
	char		buf[10];
	int			ret;

	write(STDOUT_FILENO, "\033[6n", 4);
	ret = read(STDIN_FILENO, buf, 10);
	if (ret == -1)
		return (!printf("read for cursor position failed!\n"));
	reigns->term_cursor.row = util_atoi(buf + 2);
	reigns->term_cursor.col = util_atoi(buf + 4 + 
		(reigns->term_cursor.row >= 10) +
		(reigns->term_cursor.row > 100));
	reigns->input_rows = 0;
	reigns->term_columns = 0;
	reigns->shell_cursor.col = 0;
	reigns->shell_cursor.row = 0;
	reigns->prompt_row = reigns->term_cursor.row;
	reigns->prompt_size = reigns->term_cursor.col;
	reigns->term_columns = tgetnum("co");
	reigns->term_rows = tgetnum("li");
	return (1);
}

int		reigns_get_input(t_reigns* reigns, char **line)
{
	t_vec				input;
	char				buf[6];
	int					state;

	if (!get_cursor_pos(reigns))
		return (-1);
	vec_new(&input, sizeof(char));
	while (1)
	{
		util_bzero(buf, 6);
		read(STDIN_FILENO, buf, 6);
//		printf("BUF[%d][%d][%d][%d][%d][%d]\n", (int)buf[0], (int)buf[1], (int)buf[2], (int)buf[3], (int)buf[4], (int)buf[5]);
		state = perform_action(reigns, &input, buf);
		if (state != RD_IDLE)
			break ;
	}
	if (state == RD_ERROR)
		return (-!!dprintf(2, "error state!\n"));
	buf[0] = '\0';
	if (!vec_add(&input, buf))
		return (-!!dprintf(2, "failed to null-terminate!\n"));
	*line = util_strdup(input.store);
	if (!*line)
		return (-!!dprintf(2, "strdup failed!\n"));
	return ((state == RD_EOF) ? 0 : 1);
}
