/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_get_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:04:02 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:56:08 by tishj         ########   odam.nl         */
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
	reigns->nav.cursor.y = util_atoi(buf + 2);
	reigns->nav.cursor.x = util_atoi(buf + 4 + 
		(reigns->nav.cursor.y >= 10) +
		(reigns->nav.cursor.y > 100));
	reigns->input.nav.dimension.y = 0;
	reigns->input.nav.dimension.x = 0;
	reigns->input.nav.cursor.x = 0;
	reigns->input.nav.cursor.y = 0;
	reigns->input.start.y = reigns->nav.cursor.y;
	reigns->input.start.x = reigns->nav.cursor.x;
	reigns->nav.dimension.x = tgetnum("co");
	reigns->nav.dimension.y = tgetnum("li");
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
