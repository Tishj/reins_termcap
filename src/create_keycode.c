/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_keycode.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 13:10:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/14 16:21:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

int	create_keycode(char *raw, char keycode[MAX_KEY_SIZE])
{
	if (!raw)
		return (0);
	util_bzero(keycode, MAX_KEY_SIZE);
	util_strncpy(keycode, raw, MAX_KEY_SIZE);
	return (1);
}
