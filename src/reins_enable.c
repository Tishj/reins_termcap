/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_enable.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 22:37:04 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/10 23:24:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

int	reins_enable(t_reins *reins)
{
	if (reins->enabled)
		return (1);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &reins->termios) == -1)
		return (0);
	reins->enabled = true;
	return (1);
}
