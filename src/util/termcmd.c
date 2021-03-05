/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   termcmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:52:44 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:20:10 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>

static int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void		termcmd(char *command, int p1, int p2, int lines_affected)
{
	tputs(tgoto(tgetstr(command, NULL), p1, p2), lines_affected, &putchar);
}
