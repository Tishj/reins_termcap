/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_print_keycodes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:34:46 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 15:38:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>
#include <fcntl.h>
#include <unistd.h>

int	reins_print_keycodes(t_reins *reins)
{
	char				buf[6];

	reins_enable(reins);
	while (1)
	{
		util_bzero(buf, 6);
		read(STDIN_FILENO, buf, 6);
		print_keycode_formatted(buf, 6);
	}
	return (RD_IDLE);
}
