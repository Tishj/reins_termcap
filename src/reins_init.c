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

static int	init_table(t_reins *reins)
{
	char	*termtype;

	termtype = getenv("TERM");
	if (!termtype)
		return (!printf("No termtype!\n"));
	if (tgetent(reins->table, termtype) <= 0)
		return (!printf("tgetent failed!\n"));
	return (1);
}

/*
**	IMAXBEL			-	kinda useless
**	ECHO | ICANON	-	turn off canonical mode and echo
**	VMIN			-	minimal amount of characters for non-canonical read (syscall)
**	VTIME			-	minimal time-out for non-canonical read (syscall)
**	cfset(i/o)speed -	input and output speed of the terminal,
**						affects the padding required by tputs
*/
static int	init_termios(t_reins *reins)
{
	if (!isatty(STDIN_FILENO) || tcgetattr(STDIN_FILENO, &reins->standard) < 0)
		return (0);
	reins->termios = reins->standard;
	reins->termios.c_iflag &= ~(IMAXBEL);
	reins->termios.c_lflag &= ~(ECHO | ICANON);
	reins->termios.c_cc[VMIN] = 1;
	reins->termios.c_cc[VTIME] = 0;
	return (1);
}

t_reins	*reins_init(void)
{
	t_reins	*reins;

	reins = malloc(sizeof(t_reins));
	if (!reins)
		return (NULL);
	reins->enabled = false;
	if (!init_table(reins)
		|| !init_termios(reins)
		|| !init_keys(reins))
	{
		free(reins);
		return (NULL);
	}
	return (reins);
}
