/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_home.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 13:18:17 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 13:23:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>

int	key_home(t_input *input, char *buf, t_hook *hook)
{
	(void)hook;
	(void)buf;
	reins_cursor_move(input, 0, 0, true);
	return (RD_IDLE);
}
