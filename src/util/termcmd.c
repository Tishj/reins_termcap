/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   termcmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:52:44 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/19 14:28:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <termios.h>
#include <termcap.h>
#include <unistd.h>

static int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/*
** tgetstr - Used to transform the 'command' to the corresponding
** terminal capability. (from the internal char** stored by tgetent)
**
** tgoto - Used to transform the terminal capability and its operands
** into escape sequence that the terminal understands for display commands.
**
** tputs - Adds 'padding' characters to the command to prevent the terminal
** from receiving a command while the current one is being handled.
*/
void	termcmd(char *command, int p1, int p2, int lines_affected)
{
	tputs(tgoto(tgetstr(command, NULL), p1, p2), lines_affected, &putchar);
}
