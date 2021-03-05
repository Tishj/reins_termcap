/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 13:00:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:29:50 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <term.h>
#include <ncurses.h>

static int	init_table(t_reigns* reigns)
{
	char	*termtype = getenv("TERM");
	if (!termtype)
		return (!printf("No termtype!\n"));
	if (tgetent(reigns->table, termtype) == -1)
		return (!printf("tgetent failed!\n"));
	return (1);
}

static int	init_termios(struct termios *term)
{
	if (!isatty(STDIN_FILENO) || tcgetattr(STDIN_FILENO, term) < 0)
		return (0);
	term->c_iflag &= ~(IMAXBEL); //kinda useless
	term->c_lflag &= ~(ECHO | ICANON); //turn off canonical mode and echo
	term->c_cc[VMIN] = 1; //minimal amount of characters for non-canonical read (syscall)
	term->c_cc[VTIME] = 0; //minimal time-out for non-canonical read (syscall)

	//set input/output speed to standard, set changed attributes in the terminal
	if (cfsetispeed(term, B9600) < 0 || cfsetospeed(term, B9600) < 0
		|| tcsetattr(STDIN_FILENO, TCSAFLUSH, term) < 0)
		return (!printf("failed to set attribute!\n"));
	return (1);
}

static int	get_cursor_pos(t_vec2sz* cursor)
{
	char		buf[10];
	int			ret;

	write(STDOUT_FILENO, "\033[6n", 4);
	ret = read(STDIN_FILENO, buf, 10);
	if (ret == -1)
		return (!printf("read for cursor position failed!\n"));
	cursor->y = util_atoi(buf + 2);
	cursor->x = util_atoi(buf + 4 + (cursor->y >= 10) + (cursor->y > 100));
	return (1);
}

t_reigns*	reigns_init()
{
	t_reigns*	reigns;

	reigns = malloc(sizeof(t_reigns));
	if (!reigns)
		return (NULL);
	if (!init_table(reigns) ||
		!init_termios(&reigns->termios) ||
		!get_cursor_pos(&reigns->nav.cursor))
	{
		printf("HMMM\n");
		free(reigns);
		return (NULL);
	}
	reigns->input.nav.dimension.y = 0;
	reigns->input.nav.dimension.x = 0;
	reigns->input.nav.cursor.x = reigns->nav.cursor.x;
	reigns->input.nav.cursor.y = 0;
	reigns->input.start.y = reigns->nav.cursor.y;
	reigns->input.start.x = reigns->input.nav.cursor.x;
	return (reigns);
}
