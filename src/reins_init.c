/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 13:00:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 21:14:54 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <term.h>
#include <stdio.h>

static int	init_table(t_reins* reins)
{
	char	*termtype = getenv("TERM");
	if (!termtype)
		return (!printf("No termtype!\n"));
	if (tgetent(reins->table, termtype) == -1)
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

t_reins*	reins_init()
{
	t_reins*	reins;

	reins = malloc(sizeof(t_reins));
	if (!reins)
		return (NULL);
	reins->enabled = false;
	if (!init_table(reins) ||
		!init_termios(&reins->termios) ||
		!init_keys(reins))
	{
		free(reins);
		return (NULL);
	}
	return (reins);
}
