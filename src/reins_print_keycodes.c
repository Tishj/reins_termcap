/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_print_keycodes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:34:46 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/14 16:22:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>
#include <fcntl.h>
#include <unistd.h>

int	reins_print_keycodes(t_reins *reins)
{
	char				buf[MAX_KEY_SIZE];

	reins_enable(reins);
	while (1)
	{
		util_bzero(buf, MAX_KEY_SIZE);
		read(STDIN_FILENO, buf, MAX_KEY_SIZE);
		print_keycode_formatted(buf, MAX_KEY_SIZE);
	}
	return (RD_IDLE);
}
