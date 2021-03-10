/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:39:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:15:15 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

t_key	*new_key(char keycode[6], t_keyf f)
{
	t_key	*this;

	this = malloc(sizeof(t_key));
	if (!this)
		return (NULL);
	util_bzero(this->buf, 6);
	util_memcpy(this->buf, keycode, 6);
	this->size = util_strnlen(this->buf, 6);
	this->function = f;
	this->hook.function = NULL;
	this->hook.param = NULL;
	return (this);
}
