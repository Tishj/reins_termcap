/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_disable.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 22:53:35 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/10 22:56:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

int		reins_disable(t_reins *reins)
{
	if (!reins->enabled)
		return (1);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &reins->standard) == -1)
		return (0);
	reins->enabled = false;
	return (1);
}
