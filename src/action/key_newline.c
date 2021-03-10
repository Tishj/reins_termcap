/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_newline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:38:29 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 00:29:10 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <unistd.h>

int	key_newline(t_reins *reins, t_vec *input, char *buf, t_hook *hook)
{
	if (hook && hook->function)
		hook->function(hook->param);
	(void)reins;
	(void)input;
	(void)buf;
	return (RD_SEND);
}
