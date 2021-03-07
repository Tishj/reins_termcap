/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_newline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:38:29 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:54:55 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int	key_newline(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
//	buf[0] = '\n';
//	key_regular(reigns, input, buf);
	(void)hook;
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_SEND);
}
