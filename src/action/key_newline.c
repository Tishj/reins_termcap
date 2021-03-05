/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_newline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:38:29 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:49:45 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

int	key_newline(t_reigns* reigns, t_vec* input, char *buf)
{
	buf[0] = '\n';
	key_regular(reigns, input, buf);
	return (RD_SEND);
}
