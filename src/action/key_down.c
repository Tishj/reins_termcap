/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_down.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:54:36 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <unistd.h>

int	key_down(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook)
{
	(void)hook;
	(void)reigns;
	(void)input;
	(void)buf;
	return (RD_IDLE);
}
