/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_keycode.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 13:10:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:08:22 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

int	create_keycode(char *raw, char keycode[6])
{
	if (!raw)
		return (0);
	util_bzero(keycode, 6);
	util_strncpy(keycode, raw, 6);
	return (1);
}
